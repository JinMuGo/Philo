/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 11:37:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "error.h"

bool be_born_philo(t_meta *meta)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&meta->mutex.start_mt);
	while (i < meta->args.num_of_philo)
	{
		if(pthread_create(meta->table.tids + i, NULL, begin_life, meta->table.philos + i))
			return (prt_err(ERR_THD_CREATE, THD_ERROR));
		i++;
	}
	pthread_mutex_unlock(&meta->mutex.start_mt);
	return (true);
}