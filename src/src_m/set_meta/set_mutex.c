/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:49:33 by jgo               #+#    #+#             */
/*   Updated: 2023/03/22 20:11:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

bool set_mutex(t_mutex *mutex, const int num_of_philo)
{
	int	i;

	memset(mutex, 0, sizeof(t_mutex));
	mutex->forks_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (mutex->forks_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (pthread_mutex_init(&mutex->dead_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	if (pthread_mutex_init(&mutex->start_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	if (pthread_mutex_init(&mutex->write_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	i = 0;
	while (i < num_of_philo)
	{		
		if (pthread_mutex_init(&mutex->forks_mt[i], NULL))
			return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
		i++;
	}
	return (true);
}