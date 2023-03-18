/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:10:31 by jgo               #+#    #+#             */
/*   Updated: 2023/03/18 11:03:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"
#include "utils.h"
#include "error.h"

static t_bool init_mutex(t_meta *meta)
{
	if (sc_err(pthread_mutex_init(&meta->mt_write, NULL)))
		return (FALSE);
	if (sc_err(pthread_mutex_init(&meta->mt_dead, NULL)))
		return (FALSE);
	if (sc_err(pthread_mutex_init(&meta->mt_start, NULL))) // ? 이건 내 로직에서 필요 없을 수도? thead가 생성되고 동시에 시작하게 하기 위해서 설정하는 건데 
		return (FALSE);
	
	
}

static t_bool init_table(int num_of_philo, t_philo *philos, int	*forks)
{
	const uint64_t start_time = get_ms_time();
	int	i;

	if (start_time == 0)
		return (FALSE);
	i = -1;
	while (++i < num_of_philo)
	{
		forks[i] = i;
		philos[i].num = i;
		philos[i].state = INIT;
		philos[i].fork[LEFT] = FALSE;
		philos[i].fork[RIGHT] = FALSE;
		philos[i].eat_cnt = 0;
		philos[i].start_time = start_time;
	}
	return (TRUE);
}

t_bool init(t_meta *meta, int ac, char **av)
{
	meta->num_of_philo = ft_atoi(av[1]);
	meta->time_to_die = ft_atoi(av[2]);
	meta->time_to_eat = ft_atoi(av[3]);
	meta->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		meta->num_of_must_eat = ft_atoi(av[5]);
	else
		meta->num_of_must_eat = 0;
	meta->philos = malloc(sizeof(t_philo) * (meta->num_of_philo));
	if (meta->philos == NULL)
		return (prt_err(ERR_ALLOC));
	meta->forks = malloc(sizeof(int) * (meta->num_of_philo));
	if (meta->forks == NULL)
		return (prt_err(ERR_ALLOC));
	if (init_table(meta->num_of_philo, meta->philos, meta->forks))
		return (prt_err(ERR_INIT_PHILO));
	if (init_mutex(meta))
	return (TRUE);
}