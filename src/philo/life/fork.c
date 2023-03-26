/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 14:01:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"

void	philo_take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork[L]);
	philo->box->push_rear(philo->box, write_report(philo, PHILO_FORK));
}

void	philo_take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork[R]);
	philo->box->push_rear(philo->box, write_report(philo, PHILO_FORK));
}