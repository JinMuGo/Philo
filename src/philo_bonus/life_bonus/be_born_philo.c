/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 20:28:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "error.h"
#include "utils.h"
#include "state_control.h"

static	int	create_proc(t_meta *meta)
{
	int	i;
	int	stat_loc;

	i = 0;
	sem_wait(meta->sem.start_sem); // 0 
	while (i < meta->args.num_of_philo)
	{
		meta->table.pids[i] = fork();
		if (meta->table.pids[i] == -1)
			return (-i);
		else if (meta->table.pids[i] == 0)
			begin_life(&meta->table.philo, i);
		printf("idx : %d\n", i);
		i++;
	}
	sem_post(meta->sem.start_sem);
	waitpid(-1, &stat_loc, 0);
	if (WIFEXITED(stat_loc))
	{
		printf("i'm done\n");
		while (--i >= 0)
			kill(meta->table.pids[i], SIGINT);
	}
	return (1);
}

bool	be_born_philo(t_meta *meta)
{
	int	i;

	if (get_proc_state())
		return (false);
	i = create_proc(meta);
	if (i <= 0)
	{
		while (++i <= 0)
			kill(meta->table.pids[-i], SIGINT);
		return ((prt_err(ERR_PROC_CREATE, PROC_ERROR)));
	}
	return (true);
}
