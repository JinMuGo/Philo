/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 19:02:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "err.h"
#include "life.h"
#include "mutex.h"

t_report	write_report(t_philo *philo, t_philo_state state)
{
	const t_report	report = {\
		(get_ms_time() - philo->args->start_time_of_sim), \
		philo->report.num, \
		state};

	return (report);
}

static bool	check_terminate(t_philo *philo)
{
	bool	terminate;

	pthread_mutex_lock(philo->alert->terminate_mt + philo->idx);
	terminate = philo->alert->terminate[philo->idx];
	pthread_mutex_unlock(philo->alert->terminate_mt + philo->idx);
	return (terminate);
}

static bool	check_right_fork(t_philo *philo)
{
	return (philo->fork[L] != philo->fork[R]);
}

static void	a_day_of_philo(t_philo *philo)
{
	while (!check_terminate(philo))
	{
		philo_take_left_fork(philo);
		philo_take_right_fork(philo);
		if (!check_right_fork(philo))
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	*begin_life(void *philo_arg)
{
	t_philo	*philo;

	philo = philo_arg;
	philo->report.num = philo->idx + 1;
	waiting_for_the_start(philo);
	pthread_mutex_lock(&philo->last_meal_mt);
	philo->last_meal = philo->args->start_time_of_sim;
	pthread_mutex_unlock(&philo->last_meal_mt);
	if (philo->args->num_of_philo > 1 && philo->report.num % 2 == 0)
		take_a_nap_during_that_time((philo->args->time_to_eat / 2));
	a_day_of_philo(philo);
	return (NULL);
}
