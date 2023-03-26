/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 14:26:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

static bool	set_table_mutex(pthread_mutex_t *mutex, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(mutex + i, NULL))
			return (false);
		i++;
	}
	return (true);
}

static bool setting_table(t_table *table, const int num_of_philo, t_meta *meta)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		table->philos[i].idx = i;
		table->philos[i].state = PHILO_INIT;
		table->philos[i].eat_cnt = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].box = meta->clerk.deque;
		table->philos[i].alert = &meta->alert;
		table->philos[i].args = &meta->args;
		table->philos[i].start_mt = &meta->start_mt;
		if (i == 0)
			table->philos[i].fork[L] = &meta->table.forks[num_of_philo - 1];
		else
			table->philos[i].fork[L] = &meta->table.forks[i - 1];
		table->philos[i].fork[R] = &meta->table.forks[i];
		if (pthread_mutex_init(&table->philos[i].last_meal_mt, NULL))
			return (false);
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
	if (!setting_table(table, num_of_philo, meta))
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->tids = ft_calloc(num_of_philo, sizeof(pthread_t));
	if (table->tids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->philos_mt = ft_calloc(sizeof(pthread_mutex_t), num_of_philo);
	if (table->philos_mt == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));	
	if (!set_table_mutex(table->forks, num_of_philo) || !set_table_mutex(table->philos_mt, num_of_philo))
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}