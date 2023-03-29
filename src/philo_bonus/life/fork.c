/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:37:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "queue.h"

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->fork_sem);
	sem_wait(philo->fork_sem);
	enqueue(philo->box, write_report(philo, PHILO_FORK));
	enqueue(philo->box, write_report(philo, PHILO_FORK));	
}
