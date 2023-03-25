/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 15:55:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

static bool philo_info_init(t_philo *philos, const int num_of_philo, t_meta *meta)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		philos[i].idx = i;
		philos[i].state = PHILO_INIT;
		philos[i].fork[LEFT] = false;
		philos[i].fork[RIGHT] = false;
		philos[i].eat_cnt = 0;
		philos[i].last_meal = &meta->start_time;
		philos[i].box = meta->clerk.deque;
		philos[i].alert = &meta->alert;
		philos[i].start_mt = &meta->mutex.start_mt;
		i++;
	}
	return (true);
}

static bool	set_table_mutex(pthread_mutex_t *forks_mt, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(forks_mt + i, NULL))
			return (false);
		i++;
	}
	return (true);
}

bool	set_table(t_table *table, const int num_of_philo, t_meta *meta)
{
	memset(table, 0, sizeof(t_table));
	table->philos = ft_calloc(sizeof(t_philo), num_of_philo);
	if (table->philos == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!philo_info_init(table->philos, num_of_philo, meta))
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->tids = ft_calloc(num_of_philo, sizeof(pthread_t));
	if (table->tids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->forks = ft_calloc(sizeof(t_fork_state), num_of_philo);
	if (table->forks == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->forks_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (table->forks_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!set_table_mutex(table->forks_mt, num_of_philo))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}