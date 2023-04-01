/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:50:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "err.h"
#include "life.h"
#include "sem.h"
#include "error.h"

t_report	write_report(t_philo *philo, t_philo_state state)
{
	const uint64_t	time = get_micro_time();
	t_report		report;

	report.time_stamp = (time - philo->args->start_time_of_sim) / 1000;
	report.num = philo->report.num;
	report.state = state;
	if (time == 0)
		report.num = 0;
	return (report);
}

static void	a_day_of_philo(t_philo *philo)
{
	while (true)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		if (philo->args->num_of_must_eat == philo->eat_cnt)
		{
			sem_post(philo->meta_sem->counter_sem);
			break ;
		}
		philo_sleep(philo);
		philo_think(philo);
	}
}

static bool	init_philo(t_philo *philo, const int idx)
{
	philo->idx = idx;
	philo->report.num = idx + 1;
	philo->philo_sem_name = make_philo_sem_name(idx);
	if (philo->philo_sem_name == NULL)
		return (post_and_return(philo->meta_sem->terminate_sem, false));
	close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
	philo->last_meal_sem = sem_open(philo->philo_sem_name, O_CREAT, S_IRWXU, 1);
	if (philo->last_meal_sem == SEM_FAILED)
		return (prt_err(ERR_SEM_OPEN, SEM_ERROR));
	philo->args->start_time_of_sim = get_micro_time();
	if (philo->args->start_time_of_sim == 0)
		return (prt_err(ERR_GET_TIME, TIME_ERROR));
	philo->last_meal = philo->args->start_time_of_sim;
	if (philo->args->num_of_philo > 1 && philo->report.num % 2 == 1)
		take_a_nap_during_that_time((philo->args->time_to_eat / 2));
	return (true);
}

bool	begin_life(t_philo	*philo, const int idx)
{
	if (!init_philo(philo, idx))
		return (post_and_return(philo->meta_sem->terminate_sem, \
				prt_err(ERR_INIT_PHILO, SET_ERROR)));
	if (pthread_create(&philo->moniter_thd, NULL, watch_philo_lives, philo) || \
		pthread_detach(philo->moniter_thd))
		return (post_and_return(philo->meta_sem->terminate_sem, \
			prt_err(ERR_THD_CREATE, THD_ERROR)));
	a_day_of_philo(philo);
	close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
	free(philo->philo_sem_name);
	return (true);
}
