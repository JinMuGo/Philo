/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 21:17:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "sem.h"

static void	clear_table(t_table *table)
{
	if (table->fork_sem)
		close_and_unlink_sem(table->fork_sem, FORK_SEM_NAME);
	if (table->pids)
		free(table->pids);
}

static void	clear_meta_sem(t_meta_sem *sem)
{
	if (sem->counter_sem)
		close_and_unlink_sem(sem->counter_sem, COUNTER_SEM_NAME);
	if (sem->print_sem)
		close_and_unlink_sem(sem->print_sem, PRINT_SEM_NAME);
	if (sem->terminate_sem)
		close_and_unlink_sem(sem->terminate_sem, TERM_SEM_NAME);
}

void	clear_all_asset(t_meta *meta)
{
	clear_table(&meta->table);
	clear_meta_sem(&meta->sem);
}
