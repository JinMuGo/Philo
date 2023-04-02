/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by jgo               #+#    #+#             */
/*   Updated: 2023/03/28 10:49:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"
#include "mutex.h"

bool	set_meta_mutex(t_meta_mutex *mutex, const int num_of_philo)
{
	if (pthread_mutex_init(&mutex->start_mt, NULL))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	mutex->terminate = ft_calloc(num_of_philo, sizeof(t_mutex));
	if (mutex->terminate == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!init_mutex_struct_arr(mutex->terminate, num_of_philo))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}
