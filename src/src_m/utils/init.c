/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:10:31 by jgo               #+#    #+#             */
/*   Updated: 2023/03/16 16:51:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"
#include "utils.h"

static t_bool mutex_init()
{

}

static t_bool init_philo(int num_of_philo, t_philo *philos)
{
	const uint64_t start_time = get_ms_time();
	int	i;

	i = -1;
	while (++i < num_of_philo)
	{
		philos[i].num = i + 1;
		philos[i].state = INIT;
		philos[i].fork[LEFT] = FALSE;
		philos[i].fork[RIGHT] = FALSE;
		philos[i].eat_cnt = 0;
		philos[i].start_time = start_time;
	}
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
	meta->philos = malloc(sizeof(t_philo) * (meta->num_of_philo + 1));
	if (meta->philos == NULL)
		return (prt_err(ERR_ALLOC));
	init_philo(meta->num_of_philo, meta->philos);
	
	return (TRUE);
}