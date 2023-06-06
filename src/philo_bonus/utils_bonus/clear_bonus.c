/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:41:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "utils_bonus.h"
#include "sem_bonus.h"

static void	clear_table(t_table *table)
{
	if (table->fork_sem)
		sem_unlink(FORK_SEM_NAME);
	if (table->pids)
		free(table->pids);
}

static void	clear_meta_sem(t_meta_sem *sem)
{
	if (sem->counter_sem)
		sem_unlink(COUNTER_SEM_NAME);
	if (sem->print_sem)
		sem_unlink(PRINT_SEM_NAME);
	if (sem->terminate_sem)
		sem_unlink(TERM_SEM_NAME);
}

void	clear_all_asset(t_meta *meta)
{
	clear_table(&meta->table);
	clear_meta_sem(&meta->sem);
}
