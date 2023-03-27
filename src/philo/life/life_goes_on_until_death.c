/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_goes_on_until_death.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:07 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 18:48:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "queue.h"
#include "state_control.h"

static bool	check_someone_dead(t_meta *meta)
{
	uint64_t	cur_time;
	uint64_t	last_meal;
	uint64_t	elapsed_time;
	int			i;

	i = 0;
	while (i < meta->args.num_of_philo)
	{
		pthread_mutex_lock(&meta->table.philos[i].last_meal_mt); // check
		last_meal = meta->table.philos[i].last_meal;
		pthread_mutex_unlock(&meta->table.philos[i].last_meal_mt);
		cur_time = get_ms_time();
		elapsed_time = cur_time - last_meal;
		if (elapsed_time > meta->args.time_to_die)
		{
			if (meta->args.time_to_die)
				printf("%llu %d died\n", elapsed_time, i + 1);
			else
				printf("%llu %d died\n", meta->args.time_to_die, i + 1);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	check_dining_comp(t_meta *meta)
{
	int	eat_cnt;
	int	i;

	if (meta->args.num_of_must_eat == -1)
		return (false);
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		pthread_mutex_lock(meta->alert.philos_mt + i);
		eat_cnt = meta->table.philos[i].eat_cnt;
		pthread_mutex_unlock(meta->alert.philos_mt + i);
		if (eat_cnt < meta->args.num_of_must_eat)
			return (false);
		i++;
	}
	printf("all philo complete dining!\n");
	return (true);
}

void	life_goes_on_until_death(t_meta *meta)
{
	if (get_proc_state())
		return ;
	while (!check_someone_dead(meta) && !check_dining_comp(meta))
		output(dequeue(meta->clerk.queue));
}
