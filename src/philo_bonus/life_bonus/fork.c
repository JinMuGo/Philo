/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 16:45:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "utils.h"

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->fork_sem);
	output(philo->print_sem, write_report(philo, PHILO_FORK)));
	sem_wait(philo->fork_sem);
	output(philo->print_sem, write_report(philo, PHILO_FORK)));
}
