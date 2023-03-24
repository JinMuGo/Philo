/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by jgo               #+#    #+#             */
/*   Updated: 2023/03/24 11:38:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"

bool	set_meta_mutex(t_meta_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->start_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	if (pthread_mutex_init(&mutex->dead_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}