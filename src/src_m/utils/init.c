/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:10:31 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 14:23:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"
#include "utils.h"
#include "error.h"
#include "state_control.h"

static t_bool init_mutex(t_meta *meta)
{
	int	i;

	if (sc_err(pthread_mutex_init(&meta->write_mt, NULL)))
		return (FALSE);
	if (sc_err(pthread_mutex_init(&meta->dead_mt, NULL)))
		return (FALSE);
	if (sc_err(pthread_mutex_init(&meta->start_mt, NULL))) // ? 이건 내 로직에서 필요 없을 수도? thead가 생성되고 동시에 시작하게 하기 위해서 설정하는 건데 
		return (FALSE);
	i = -1;
	while (++i < meta->num_of_philo)
	{
		if (sc_err(pthread_mutex_init(&meta->forks_mt[i], NULL)))
			return (FALSE);
	}
	return (TRUE);
}

static t_bool init_table(int num_of_philo, t_philo *philos, int	*forks)
{
	const uint64_t begin_time = get_ms_time();
	int	i;

	i = -1;
	while (++i < num_of_philo)
	{
		forks[i] = ON_TABLE;
		philos[i].num = i;
		philos[i].state = PHILO_INIT;
		philos[i].fork[LEFT] = FALSE;
		philos[i].fork[RIGHT] = FALSE;
		philos[i].eat_cnt = 0;
		philos[i].last_meal = begin_time;
	}
	return (TRUE);
}

t_bool init(t_meta *meta, int ac, char **av)
{

	meta->num_of_philo = char_to_uint64(av[1]);
	meta->time_to_die = char_to_uint64(av[2]);
	meta->time_to_eat = char_to_uint64(av[3]);
	meta->time_to_sleep = char_to_uint64(av[4]);
	if (ac == 6)
		meta->num_of_must_eat = char_to_uint64(av[5]);
	else
		meta->num_of_must_eat = 0;
	if(get_proc_state() == PROC_ERROR)
		return (prt_err(ERR_INVALID_ARGS));
	meta->philos = malloc(sizeof(t_philo) * (meta->num_of_philo));
	if (meta->philos == NULL)
		return (prt_err(ERR_ALLOC));
	meta->forks = malloc(sizeof(int) * (meta->num_of_philo));
	if (meta->forks == NULL)
		return (prt_err(ERR_ALLOC));
	init_table(meta->num_of_philo, meta->philos, meta->forks);
	if (init_mutex(meta))
		return (prt_err(ERR_INIT_MUTEX));
	return (TRUE);
}