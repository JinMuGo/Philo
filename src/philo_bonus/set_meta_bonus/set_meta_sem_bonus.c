/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 23:22:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "error_bonus.h"
#include "utils_bonus.h"
#include "sem_bonus.h"

bool	set_meta_sem(t_meta_sem *sem)
{
	close_and_unlink_sem(sem->counter_sem, COUNTER_SEM_NAME);
	close_and_unlink_sem(sem->terminate_sem, TERM_SEM_NAME);
	close_and_unlink_sem(sem->print_sem, PRINT_SEM_NAME);
	sem->counter_sem = sem_open(COUNTER_SEM_NAME, O_CREAT, S_IRWXU, 0);
	if (sem->counter_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->terminate_sem = sem_open(TERM_SEM_NAME, O_CREAT, S_IRWXU, 0);
	if (sem->terminate_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->print_sem = sem_open(PRINT_SEM_NAME, O_CREAT, S_IRWXU, 1);
	if (sem->print_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}
