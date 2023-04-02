/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philo_lives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:53:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "utils_bonus.h"
#include "state_control_bonus.h"
#include "sem_bonus.h"

static void	print_dead_msg(t_philo *philo, const uint64_t elapsed_time)
{
	if (philo->args->time_to_die)
		printf(RED"%llu %d died\n"RESET, \
			elapsed_time / 1000, philo->idx + 1);
	else
		printf(RED"%llu %d died\n"RESET, \
			philo->args->time_to_die, philo->idx + 1);
}

static bool	check_dead(t_philo *philo)
{
	uint64_t	elapsed_time;
	uint64_t	cur_time;

	usleep(philo->args->num_of_philo * 100);
	while (true)
	{
		sem_wait(philo->last_meal_sem);
		cur_time = get_micro_time();
		elapsed_time = cur_time - philo->last_meal;
		sem_post(philo->last_meal_sem);
		if (elapsed_time > philo->args->time_to_die)
		{
			sem_wait(philo->meta_sem->print_sem);
			print_dead_msg(philo, elapsed_time);
			close_and_unlink_sem(philo->last_meal_sem, philo->philo_sem_name);
			free(philo->philo_sem_name);
			sem_post(philo->meta_sem->terminate_sem);
			break ;
		}
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
