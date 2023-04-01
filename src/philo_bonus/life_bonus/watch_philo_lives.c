/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philo_lives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:26:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "state_control.h"
#include "sem.h"

static bool	check_dead(t_philo *philo)
{
	uint64_t	elapsed_time;

	while (true)
	{
		sem_wait(philo->last_meal_sem);
		elapsed_time = get_micro_time() - philo->last_meal;
		sem_post(philo->last_meal_sem);
		if (elapsed_time > philo->args->time_to_die)
		{
			sem_wait(philo->print_sem);
			if (philo->args->time_to_die)
				printf(RED"%llu %d died\n"RESET, \
					elapsed_time / 1000, philo->idx + 1);
			else
				printf(RED"%llu %d died\n"RESET, \
					philo->args->time_to_die, philo->idx + 1);
			close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
			free(philo->philo_sem_name);
			sem_post(philo->terminate_sem);
			exit(EXIT_SUCCESS);
		}
		usleep(philo->args->num_of_philo * 100);
	}
	exit (EXIT_SUCCESS);
}

void	*watch_philo_lives(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (get_proc_state())
		return (NULL);
	while (!check_dead(philo))
		continue ;
	return (NULL);
}
