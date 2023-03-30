/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 15:09:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"
#include "mutex.h"

bool set_meta_sem(t_meta_sem *sem, const int num_of_philo)
{
	sem->start_sem = sem_open(START_SEM_NAME, O_CREAT, 0644, 1);
	if (sem->start_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->print_sem  = sem_open(START_SEM_NAME, O_CREAT, 0644, 1);
	if (sem->print_sem  == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	return (true);
}
