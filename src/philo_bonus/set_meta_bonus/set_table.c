/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:16 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:26:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "sem.h"
#include "error.h"
#include "utils.h"
#include "set_meta.h"

static void	setting_table(t_meta *meta, t_table *table)
{
	table->philo.args = &meta->args;
	table->philo.fork_sem = table->fork_sem;
	table->philo.meta_sem = &meta->sem;
}

bool	set_table(t_table *table, const int num_of_philo, t_meta *meta)
{
	memset(table, 0, sizeof(t_table));
	close_and_unlink_sem(table->fork_sem, FORK_SEM_NAME);
	table->fork_sem = sem_open(FORK_SEM_NAME, O_CREAT, S_IRWXU, num_of_philo);
	if (table->fork_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	table->pids = ft_calloc(num_of_philo, sizeof(pid_t));
	if (table->pids == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	setting_table(meta, table);
	return (true);
}
