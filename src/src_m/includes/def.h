/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:43:05 by jgo               #+#    #+#             */
/*   Updated: 2023/03/21 11:35:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

#include "enum.h"
#include "const.h"

typedef struct s_meta t_meta;
typedef struct s_philo t_philo;
typedef struct s_state	t_state;
typedef struct s_args	t_args;
typedef struct s_table t_table;
typedef struct s_mutex	t_mutex;

struct s_mutex
{
	pthread_mutex_t	*forks_mt;
	pthread_mutex_t	start_mt;
	pthread_mutex_t	write_mt;
	pthread_mutex_t	dead_mt;	
};

struct s_table
{
	t_philo			*philos;
	pthread_t		*tids;
	t_fork_state	*forks;
};

struct s_args
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
};

struct s_meta
{
	t_args			args;
	bool			someone_dead;
	t_table			table;
	t_mutex			mutex;
};

struct s_state
{
	t_proc_state state;
};

struct s_philo
{
	int				num;
	t_philo_state	state;
	bool			fork[2];
	int				eat_cnt;
	uint64_t		last_meal;
};

#endif