/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 10:28:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "life.h"
#include "queue.h"
#include "mutex.h"

void	philo_eat(t_philo *philo)
{
	set_sem_value(&philo->last_meal, sizeof(uint64_t), 0);
	enqueue(philo->box, write_report(philo, PHILO_EAT));
	if (philo->args->num_of_must_eat != -1)
		set_sem_value(&philo->eat_cnt, sizeof(int), 0);
	take_a_nap_during_that_time(philo->args->time_to_eat);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
}
