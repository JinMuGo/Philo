/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:43:05 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 10:33:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

#include "enum.h"
#include "constants.h"

typedef struct s_meta t_meta;
typedef struct s_philo t_philo;
typedef struct s_state	t_state;

struct s_meta
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
	t_philo			*philos;
	int				*forks;
	pthread_mutex_t	*forks_mt;
	pthread_mutex_t	start_mt;
	pthread_mutex_t	write_mt;
	pthread_mutex_t	dead_mt;
};

struct s_state
{
	t_proc_state state;
};


struct s_philo
{
	int			num;
	t_philo_state		state;
	t_bool		fork[2];
	int			eat_cnt;
	uint64_t	start_time;
};

#endif