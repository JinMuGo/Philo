/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 16:20:15 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "err.h"
#include "life.h"

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
	while (!philo->terminate)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		if (philo->args->num_of_must_eat == philo->eat_cnt)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
}



void	begin_life(t_philo	*philo, const int idx)
{
	philo->report.num = idx + 1;
	waiting_for_the_start(philo);
	philo->args->start_time_of_sim = get_micro_time();
	philo->last_meal = philo->args->start_time_of_sim;
	pthread_create(&philo->moniter_mt, NULL, watch_philo_lives, philo);
	a_day_of_philo(philo);
	pthread_join(philo->moniter_mt, NULL);
}
