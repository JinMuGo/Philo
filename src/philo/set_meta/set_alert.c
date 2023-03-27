/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_alert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:00:19 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 15:13:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"
#include "set_meta.h"

bool set_alert(t_alert *alert, const int num_of_philo)
{
	memset(alert, 0, sizeof(t_alert));
	alert->terminate = ft_calloc(sizeof(bool), num_of_philo);
	if (alert->terminate == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	alert->terminate_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (alert->terminate_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	alert->philos_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (alert->philos_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));	
	if (!set_mutex_arr(alert->terminate_mt, num_of_philo) || \
		!set_mutex_arr(alert->philos_mt, num_of_philo))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}