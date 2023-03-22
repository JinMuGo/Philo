/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/22 11:16:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"

bool make_philo(t_meta *meta)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&meta->start_mt);
	while (i < meta->num_of_philo)
	{
		pthread_create(&meta->tids[i], NULL, begin_life, &meta->philos[i]);
		
		i++;
	}
	pthread_mutex_unlock(&meta->start_mt);
	return (true);
}