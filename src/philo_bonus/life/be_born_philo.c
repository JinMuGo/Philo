/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:23:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "error.h"
#include "utils.h"
#include "state_control.h"

bool	be_born_philo(t_meta *meta)
{
	int	i;

	if (get_proc_state())
		return (false);
	i = 0;
	sem_wait(&meta->sem.start_sem);
	while (i < meta->args.num_of_philo)
	{
		meta->table.pids[i] = fork();
		if (meta->table.pids[i] == -1)
			return (prt_err(ERR_PROC_CREATE, PROC_ERROR));
		else if (meta->table.pids[i] == 0)
			begin_life(&meta->table.philos[i]);
		i++;
	}
	meta->args.start_time_of_sim = get_micro_time();
	sem_post(&meta->sem.start_sem);
	if (meta->args.time_to_die)
		take_a_nap_during_that_time(meta->args.time_to_die * 0.7);
	return (true);
}
