/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:16:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "utils_bonus.h"
#include "life_bonus.h"

void	philo_eat(t_philo *philo)
{
	if (sem_wait(philo->last_meal_sem))
		sem_post(philo->meta_sem->terminate_sem);
	philo->last_meal = get_micro_time();
	sem_post(philo->last_meal_sem);
	output(philo->meta_sem->print_sem, write_report(philo, PHILO_EAT));
	take_a_nap_during_that_time(philo->args->time_to_eat);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
	philo->eat_cnt++;
}
