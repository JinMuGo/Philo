/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/03/28 10:51:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"
#include "set_meta.h"
#include "mutex.h"

static bool	setting_table(t_meta *meta, t_table *table, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		table->philos[i].idx = i;
		table->philos[i].box = meta->clerk.queue;
		table->philos[i].args = &meta->args;
		table->philos[i].start_mt = &meta->mutex.start_mt;
		if (i == 0)
			table->philos[i].fork[L] = &meta->table.forks[num_of_philo - 1];
		else
			table->philos[i].fork[L] = &meta->table.forks[i - 1];
		table->philos[i].fork[R] = &meta->table.forks[i];
		table->philos[i].terminate = meta->mutex.terminate + i;
		if (pthread_mutex_init(&table->philos[i].eat_cnt.mt, NULL))
			return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
		if (pthread_mutex_init(&table->philos[i].last_meal.mt, NULL))
			return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
		i++;
	}
	return (true);
}

bool	set_table(t_table *table, const int num_of_philo, t_meta *meta)
{
	memset(table, 0, sizeof(t_table));
	table->forks = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (table->forks == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->philos = ft_calloc(sizeof(t_philo), num_of_philo);
	if (table->philos == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->tids = ft_calloc(num_of_philo, sizeof(pthread_t));
	if (table->tids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!setting_table(meta, table, num_of_philo))
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!init_mutex_arr(table->forks, num_of_philo))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}
