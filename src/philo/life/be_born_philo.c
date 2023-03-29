/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 10:27:29 by jgo              ###   ########.fr       */
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
	pthread_mutex_lock(&meta->mutex.start_mt);
	while (i < meta->args.num_of_philo)
	{
		if (pthread_create(\
				meta->table.tids + i, \
				NULL, \
				begin_life, \
				meta->table.philos + i))
			return (prt_err(ERR_THD_CREATE, THD_ERROR));
		i++;
	}
	meta->args.start_time_of_sim = get_micro_time();
	pthread_mutex_unlock(&meta->mutex.start_mt);
	if (meta->args.time_to_die)
		take_a_nap_during_that_time(meta->args.time_to_die * 0.7);
	return (true);
}
