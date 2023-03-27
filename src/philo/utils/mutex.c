/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:48 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 18:57:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"

// 값을 얻어오는 행동 int uint64_t bool
// 값을 쓰는 행동 int uint64_t bool

void	get_mutexed_value(void *dst, void *val, pthread_mutex_t mutex)
{

}

void	set_mutexed_value(void *dst, void *val, pthread_mutex_t mutex)
{

}

void    waiting_for_the_start(t_philo *philo)
{
	pthread_mutex_lock(philo->start_mt);
	pthread_mutex_unlock(philo->start_mt);
}