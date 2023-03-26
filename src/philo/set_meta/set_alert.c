/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_alert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:00:19 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 21:02:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

bool set_alert(t_alert *alert, const int num_of_philo)
{
	int	i;
	
	memset(alert, 0, sizeof(t_alert));
	alert->terminate = ft_calloc(sizeof(bool), num_of_philo);
	if (alert->terminate == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	alert->terminate_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (alert->terminate_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(alert->terminate_mt + i, NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&alert->alert_mt, NULL))
		return (false);
	return (true);
}