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

/*-------------- INCLUDE --------------*/
# include "enum.h"
# include "const.h"

/*-------------- TYPEDEF --------------*/
typedef struct s_meta		t_meta;
typedef struct s_philo		t_philo;
typedef struct s_state		t_state;
typedef struct s_args		t_args;
typedef struct s_table		t_table;
typedef struct s_queue		t_queue;
typedef struct s_clerk		t_clerk;
typedef struct s_report		t_report;
typedef struct s_mutex		t_mutex;
typedef struct s_terminate	t_terminate;
typedef struct s_meta_mutex	t_meta_mutex;

typedef union u_mutex_val	t_u_mutex_val;

/*-------------- UNION --------------*/
union u_mutex_val
{
	int			i;
	bool		b;
	uint64_t	u;
};

/*-------------- STRUCT --------------*/
struct s_state
{
	t_proc_state	state;
};

struct s_report
{
	uint64_t		time_stamp;
	int				num;
	t_philo_state	state;
};

struct s_queue
{
	int				size;
	int				front;
	int				rear;
	t_report		*papers;
	pthread_mutex_t	queue_mt;
};

struct s_mutex
{
	t_u_mutex_val	val;
	pthread_mutex_t	mt;
};

struct s_philo
{
	int				idx;
	t_args			*args;
	t_queue			*box;
	t_report		report;
	t_mutex			eat_cnt;
	t_mutex			last_meal;
	t_mutex			*terminate;
	pthread_mutex_t	*fork[2];
	pthread_mutex_t	*start_mt;
};

struct s_args
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
	uint64_t		start_time_of_sim;
};
struct s_clerk
{
	t_queue	*queue;
};

struct s_table
{
	t_philo			*philos;
	pthread_t		*tids;
	pthread_mutex_t	*forks;
};

struct s_meta_mutex
{
	t_mutex			*terminate;
	pthread_mutex_t	start_mt;
};

struct s_meta
{
	t_args			args;
	t_clerk			clerk;
	t_table			table;
	t_meta_mutex	mutex;
};

#endif