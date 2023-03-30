/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:38:03 by jgo              ###   ########.fr       */
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
		(get_micro_time() - philo->args->start_time_of_sim) / 1000, \
		philo->report.num, \
		state};

	return (report);
}

static bool	check_terminate(t_philo *philo)
{
	t_sem	terminate;

	get_sem_value(&terminate, philo->terminate, sizeof(bool));
	return (terminate.val.b);
}

static void	a_day_of_philo(t_philo *philo)
{
	while (!check_terminate(philo))
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	begin_life(t_philo	*philo)
{
	philo->report.num = philo->idx + 1;
	waiting_for_the_start(philo);
	set_sem_value(\
		&philo->last_meal, \
		sizeof(uint64_t), \
		philo->args->start_time_of_sim);
	if (philo->args->num_of_philo > 1 && philo->report.num % 2 == 1)
		take_a_nap_during_that_time((philo->args->time_to_eat / 2));
	a_day_of_philo(philo);
	exit(EXIT_SUCCESS);
}
