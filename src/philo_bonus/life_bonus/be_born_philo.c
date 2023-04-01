/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:54:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "error.h"
#include "utils.h"
#include "state_control.h"

static void	*meal_counter(void *arg)
{
	t_meta	*meta;
	int		cnt;

	meta = arg;
	cnt = 0;
	while (true)
	{
		if (sem_wait(meta->sem.counter_sem) == SC_ERR)
		{
			sem_post(meta->sem.terminate_sem);
			break ;
		}
		if (++cnt == meta->args.num_of_philo)
		{
			if (sem_wait(meta->sem.print_sem) == SC_ERR)
				sem_post(meta->sem.terminate_sem);
			printf(CYAN"all philo complete dining!\n"RESET);
			sem_post(meta->sem.terminate_sem);
			break ;
		}
	}
	return (NULL);
}

static	int	create_philo(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->args.num_of_philo)
	{
		meta->table.pids[i] = fork();
		if (meta->table.pids[i] == SC_ERR)
			return (-i);
		else if (meta->table.pids[i] == 0)
		{
			begin_life(&meta->table.philo, i);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	if (sem_wait(meta->sem.terminate_sem) == SC_ERR)
		return (-i);
	return (1);
}

bool	be_born_philo(t_meta *meta)
{
	int	is_err;

	if (get_proc_state())
		return (false);
	if (meta->args.num_of_must_eat != -1)
	{
		if (pthread_create(&meta->meal_counter, NULL, meal_counter, meta) || \
			pthread_detach(meta->meal_counter))
			return (prt_err(ERR_THD_CREATE, THD_ERROR));
	}
	is_err = create_philo(meta);
	if (is_err <= 0)
	{
		while (++is_err <= 0)
			kill(meta->table.pids[-is_err], SIGKILL);
		return ((prt_err(ERR_PROC_CREATE, PROC_ERROR)));
	}
	return (true);
}
