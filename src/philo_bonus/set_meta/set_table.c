/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:13:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"
#include "set_meta.h"
#include "mutex.h"

static void	setting_table(t_meta *meta, t_table *table, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		table->philos[i].idx = i;
		table->philos[i].box = meta->clerk.queue;
		table->philos[i].args = &meta->args;
		table->philos[i].start_sem = meta->sem.start_sem;
		table->philos[i].fork_sem = meta->table.fork_sem;
		table->philos[i].terminate = meta->sem.terminate + i;
		table->philos[i].eat_cnt.sem = meta->sem.eat_cnt_sem;
		table->philos[i].last_meal.sem = meta->sem.last_meal_sem;
		i++;
	}
}

bool	set_table(t_table *table, const int num_of_philo, t_meta *meta)
{
	memset(table, 0, sizeof(t_table));
	table->fork_sem = sem_open(FORK_SEM_NAME, O_CREAT | O_EXCL, 0644, num_of_philo);
	if (table->fork_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	table->philos = ft_calloc(sizeof(t_philo), num_of_philo);
	if (table->philos == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	table->pids = ft_calloc(num_of_philo, sizeof(pid_t));
	if (table->pids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	setting_table(meta, table, num_of_philo);
	return (true);
}
