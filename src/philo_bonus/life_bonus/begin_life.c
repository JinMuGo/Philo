/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:13:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "err.h"
#include "life.h"
#include "sem.h"

t_report	write_report(t_philo *philo, t_philo_state state)
{
	const t_report	report = {\
		(get_micro_time() - philo->args->start_time_of_sim) / 1000, \
		philo->report.num, \
		state};

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
			sem_post(philo->counter_sem);
			break ;
		}
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	begin_life(t_philo	*philo, const int idx)
{
	philo->idx = idx;
	philo->report.num = idx + 1;
	philo->args->start_time_of_sim = get_micro_time();
	philo->last_meal = philo->args->start_time_of_sim;
	philo->philo_sem_name = make_philo_sem_name(idx);
	if (philo->philo_sem_name == NULL)
		sem_post(philo->terminate_sem);
	close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
	philo->last_meal_sem = sem_open(philo->philo_sem_name, O_CREAT, S_IRWXU, 1);
	if (philo->args->num_of_philo > 1 && philo->report.num % 2 == 1)
		take_a_nap_during_that_time((philo->args->time_to_eat / 2));
	pthread_create(&philo->moniter_thd, NULL, watch_philo_lives, philo);
	pthread_detach(philo->moniter_thd);
	a_day_of_philo(philo);
	close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
	free(philo->philo_sem_name);
}
