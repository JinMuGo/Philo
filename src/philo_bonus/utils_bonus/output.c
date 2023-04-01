/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:42:09 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 21:14:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"

static char	*get_philo_state_msg(t_philo_state state)
{
	if (state == PHILO_FORK)
		return (FORK_MSG);
	else if (state == PHILO_EAT)
		return (EAT_MSG);
	else if (state == PHILO_SLEEP)
		return (SLEEP_MSG);
	else if (state == PHILO_THINK)
		return (THINK_MSG);
	return (DIED_MSG);
}

void	output(sem_t *print_sem, t_report report)
{
	if (report.num == 0)
		return ;
	sem_wait(print_sem);
	printf(\
		"%llu %d %s", \
		report.time_stamp, \
		report.num, \
		get_philo_state_msg(report.state));
	sem_post(print_sem);
}
