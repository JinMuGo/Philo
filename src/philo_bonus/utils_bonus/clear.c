/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 10:27:49 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "mutex.h"

static void	clear_clerk(t_clerk *clerk)
{
	if (clerk->queue == NULL)
		return ;
	if (clerk->queue->papers)
		free(clerk->queue->papers);
	if (clerk->queue->queue_sem)
		close_and_unlink_sem(clerk->queue->queue_sem, QUEUE_SEM_NAME);
	if (clerk->queue)
		free(clerk->queue);
}

static void	clear_table(t_table *table)
{
	if (table->fork_sem)
		close_and_unlink_sem(table->fork_sem, FORK_SEM_NAME);
	if (table->pids)
		free(table->pids);
	if (table->philos)
		free(table->philos);
}

static void	clear_meta_sem(t_meta_sem *sem)
{
	if (sem->terminate)
		free(sem->terminate);
	if (sem->start_sem)
		close_and_unlink_sem(sem->start_sem, START_SEM_NAME);
	if (sem->terminate_sem)
		close_and_unlink_sem(sem->terminate_sem, TERMINATE_SEM_NAME);
	if (sem->eat_cnt_sem)
		close_and_unlink_sem(sem->eat_cnt_sem, EAT_CNT_SEM_NAME);
	if (sem->last_meal_sem)
		close_and_unlink_sem(sem->last_meal_sem, LAST_MEAL_SEM_NAME);	
}

void	clear_all_asset(t_meta *meta)
{
	clear_clerk(&meta->clerk);
	clear_table(&meta->table);
	clear_meta_sem(&meta->sem);
}
