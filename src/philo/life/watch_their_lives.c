/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_their_lives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 16:48:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "queue.h"
#include "state_control.h"
#include "mutex.h"

static bool	check_someone_dead(t_meta *meta)
{
	uint64_t	cur_time;
	t_mutex		last_meal;
	uint64_t	elapsed_time;
	int			i;

	i = 0;
	while (i < meta->args.num_of_philo)
	{
		get_mutex_value(\
			&last_meal, \
			&meta->table.philos[i].last_meal, \
			sizeof(uint64_t));
		cur_time = get_micro_time();
		elapsed_time = cur_time - last_meal.val.u;
		if (elapsed_time > meta->args.time_to_die)
		{
			if (meta->args.time_to_die)
				printf(RED"%llu %d died\n"RESET, elapsed_time / 1000, i + 1);
			else
				printf(RED"%llu %d died\n"RESET, meta->args.time_to_die, i + 1);
			return (true);
		}
		i++;
	}
	return (false);
}

static void	finish_dining(t_clerk *clerk)
{
	t_report	*report;

	while (!is_empty(clerk->queue))
	{
		report = dequeue(clerk->queue);
		output(report);
	}
	printf(CYAN"all philo complete dining!\n"RESET);
}

static bool	check_dining_comp(t_meta *meta)
{
	int		i;
	t_mutex	eat_cnt;

	if (meta->args.num_of_must_eat == -1)
		return (false);
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		get_mutex_value(&eat_cnt, &meta->table.philos[i].eat_cnt, sizeof(int));
		if (eat_cnt.val.i < meta->args.num_of_must_eat)
			return (false);
		i++;
	}
	finish_dining(&meta->clerk);
	return (true);
}

bool	watch_their_lives(t_meta *meta)
{
	if (get_proc_state())
		return (false);
	while (!check_someone_dead(meta) && !check_dining_comp(meta))
		output(dequeue(meta->clerk.queue));
	return (true);
}
