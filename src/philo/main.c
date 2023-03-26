/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:34:52 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 14:33:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "error.h"
#include "set_meta.h"
#include "life.h"
#include "dead_command.h"

static bool	check_someone_dead(t_meta *meta)
{
	uint64_t	cur_time;
	uint64_t	last_meal;
	uint64_t	elapsed_time;
	int	i;

	i = 0;
	while (i < meta->args.num_of_philo)
	{
		cur_time = get_ms_time();
		pthread_mutex_lock(&meta->table.philos[i].last_meal_mt);
		last_meal = meta->table.philos[i].last_meal;
		pthread_mutex_unlock(&meta->table.philos[i].last_meal_mt);
		elapsed_time = cur_time - last_meal;
		if (elapsed_time > meta->args.time_to_die)
		{
			printf("%llu %d died\n", elapsed_time, i + 1);
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
		pthread_mutex_lock(meta->table.philos_mt + i);
		eat_cnt = meta->table.philos[i].eat_cnt;
		pthread_mutex_unlock(meta->table.philos_mt + i);
		if (eat_cnt < meta->args.num_of_must_eat)
			return (false);
		i++;
	}
	return (true);
}

static void life_goes_on_until_death(t_meta *meta)
{
	while (!check_someone_dead(meta) && !check_dining_comp(meta))
	{
		output(meta->clerk.deque->pop_front(meta->clerk.deque));
	}

}

void	wait_terminate_philo(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->args.num_of_philo)
	{
		pthread_mutex_lock(meta->alert.terminate_mt + i);
		meta->alert.terminate[i] = true;
		pthread_mutex_unlock(meta->alert.terminate_mt + i);
		i++;
	}
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		pthread_join(meta->table.tids[i], NULL);
		i++;
	}
}

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat optional
// philosopher

int main(int ac, char **av)
{
	t_meta meta;

	if (ac < 5 || 6 < ac)
		return (prt_err(ERR_ARGS, SET_ERROR));
	set_meta(&meta, ac, av);
	be_born_philo(&meta);
	// ---------------------
	life_goes_on_until_death(&meta);
	wait_terminate_philo(&meta);
	clear_all_asset(&meta);
	system("leaks philo");
	return (EXIT_SUCCESS);
}