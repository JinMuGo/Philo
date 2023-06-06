/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:16:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "life_bonus.h"
#include "utils_bonus.h"

void	philo_take_fork(t_philo *philo)
{
	if (sem_wait(philo->fork_sem) == SC_ERR)
		sem_post(philo->meta_sem->terminate_sem);
	output(philo->meta_sem->print_sem, write_report(philo, PHILO_FORK));
	if (sem_wait(philo->fork_sem) == SC_ERR)
		sem_post(philo->meta_sem->terminate_sem);
	output(philo->meta_sem->print_sem, write_report(philo, PHILO_FORK));
}
