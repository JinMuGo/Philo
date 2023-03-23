/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 17:19:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

static bool philo_info_init(t_philo *philos, const int num_of_philo, const t_deque *deque)
{
	const uint64_t begin_time = get_ms_time();
	int	i;

	if (begin_time == 0)
		return (false);
	i = 0;
	while (i < num_of_philo)
	{
		philos[i].num = i;
		philos[i].state = PHILO_INIT;
		philos[i].fork[LEFT] = false;
		philos[i].fork[RIGHT] = false;
		philos[i].eat_cnt = 0;
		philos[i].last_meal = begin_time;
		philos[i].deque = deque;
		i++;
	}
	return (true);
}

bool	set_table(t_table *table, const int num_of_philo, const t_deque *deque)
{
	memset(table, 0, sizeof(t_table));
	table->philos = ft_calloc(sizeof(t_philo), num_of_philo);
	if (table->philos == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	if (!philo_info_init(table->philos, num_of_philo, deque))
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->forks = ft_calloc(sizeof(t_fork_state), num_of_philo);
	if (table->forks == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->tids = ft_calloc(num_of_philo, sizeof(pthread_t));
	if (table->tids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	return (true);
}