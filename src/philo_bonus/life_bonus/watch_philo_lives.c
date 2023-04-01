/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philo_lives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 22:40:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "state_control.h"

static void kill_proc_arr(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philo)
	{
		kill(philo->pids[i], SIGINT);
		i++;
	}
}

static bool	check_dead(t_philo *philo)
{
	uint64_t	cur_time;
	uint64_t	elapsed_time;
	bool		terminate;

	terminate = false;
	while (!terminate)
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
			kill_proc_arr(philo);
			exit(EXIT_SUCCESS);
		}
		usleep(philo->args->num_of_philo * 100);
	}
	exit (EXIT_SUCCESS);
}

void	*watch_philo_lives(void *arg)
{
	t_philo *philo;

	philo = arg;
	if (get_proc_state())
		return (NULL);
	while (!check_dead(philo))
		continue ;
	return (NULL);
}
