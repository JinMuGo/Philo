/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 14:01:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "life.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_mt);
	philo->last_meal = get_ms_time();
	pthread_mutex_unlock(&philo->last_meal_mt);
	philo->box->push_rear(philo->box, write_report(philo, PHILO_EAT));
	take_a_nap_during_that_time(philo->args->time_to_eat);
	pthread_mutex_unlock(philo->fork[L]);
	pthread_mutex_unlock(philo->fork[R]);
}