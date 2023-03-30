/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philo_lives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 18:05:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "state_control.h"

static bool	check_dead(t_philo *philo)
{
	uint64_t	cur_time;
	uint64_t	last_meal;
	uint64_t	elapsed_time;

	while (true)
	{
		cur_time = get_micro_time();
		elapsed_time = cur_time - philo->last_meal;
		if (elapsed_time > philo->args->time_to_die)
		{
			sem_wait(philo->print_sem);
			if (philo->args->time_to_die)
				printf(RED"%llu %d died\n"RESET, elapsed_time / 1000, philo->idx + 1);
			else
				printf(RED"%llu %d died\n"RESET, philo->args->time_to_die, philo->idx + 1);
			sem_post(philo->print_sem);
			exit(EXIT_SUCCESS);
			return (true);
		}
		usleep(philo->args->num_of_philo);
	}
	return (false);
}

void	*watch_philo_lives(t_philo *philo)
{
	if (get_proc_state())
		return (NULL);
	while (!check_dead(philo))
		continue ;
	return (NULL);
}
