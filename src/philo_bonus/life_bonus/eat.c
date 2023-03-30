/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 16:48:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "life.h"
#include "mutex.h"

void	philo_eat(t_philo *philo)
{
	philo->last_meal = get_micro_time();
	output(philo->print_sem, write_report(philo, PHILO_EAT));
	take_a_nap_during_that_time(philo->args->time_to_eat);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
	philo->eat_cnt++;
}
