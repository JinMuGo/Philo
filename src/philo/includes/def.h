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
typedef struct s_deque	t_deque;
typedef struct s_clerk t_clerk;
typedef	struct s_report t_report;
typedef struct s_meta_mutex t_meta_mutex;
typedef struct s_alert t_alert;

struct s_alert
{
	bool	*terminate;
	pthread_mutex_t	*alert_mt;

};

struct s_table
{
	t_philo			*philos;
	pthread_t		*tids;
	t_fork_state	*forks;
	pthread_mutex_t	*forks_mt;
};

struct s_args
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
};

struct s_clerk
{
	t_deque *deque;
};

struct s_meta_mutex
{
	pthread_mutex_t	start_mt;
	pthread_mutex_t	dead_mt;
};

struct s_meta
{
	t_args			args;
	t_clerk			clerk;
	t_table			table;
	t_meta_mutex	mutex;
	t_alert			alert;
	uint64_t		start_time;
};

struct s_state
{
	t_proc_state state;
};

struct s_report
{
	uint64_t		time_stamp;
	int				num;
	t_philo_state	state;
};

struct s_philo
{
	int				idx;
	t_philo_state	state;
	bool			fork[2];
	int				eat_cnt;
	uint64_t		*last_meal;
	t_report		report;
	t_deque			*box;
	t_alert			*alert;
	pthread_mutex_t	*start_mt;
};

struct s_deque
{
	pthread_mutex_t	queue_mt;
	size_t			 capacity;
	size_t 			 front;
	size_t 			 rear;
	size_t 			 use_size;
	void    		**nodes;
	void    		(*push_front)(t_deque *, void *);
	void    		(*push_rear)(t_deque *, void *);
	void    		*(*pop_front)(t_deque *);
	void    		*(*pop_rear)(t_deque *);
	void    		*(*peek_front)(const t_deque *);
	void    		*(*peek_rear)(const t_deque *);
};

#endif