/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:36:58 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 10:47:59 by jgo              ###   ########.fr       */
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
	sem->terminate_sem = sem_open(TERMINATE_SEM_NAME, O_CREAT, 0644, num_of_philo);
	if (sem->terminate_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->eat_cnt_sem = sem_open(EAT_CNT_SEM_NAME, O_CREAT, 0644, num_of_philo);
	if (sem->eat_cnt_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->last_meal_sem = sem_open(LAST_MEAL_SEM_NAME, O_CREAT, 0644, num_of_philo);
	if (sem->last_meal_sem == SEM_FAILED)
		return (prt_err(ERR_INIT_MUTEX, SET_ERROR));
	sem->terminate = ft_calloc(num_of_philo, sizeof(t_sem));
	if (sem->terminate == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	init_sem_struct_arr(sem->terminate_sem, sem->terminate, num_of_philo);
	return (true);
}
