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
typedef struct s_queue	t_queue;
typedef struct s_clerk t_clerk;
typedef	struct s_report t_report;
typedef struct s_alert t_alert;

struct s_alert
{
	int				ready_cnt;
	bool			*terminate;
	pthread_mutex_t	alert_mt;
	pthread_mutex_t	*terminate_mt;
	pthread_mutex_t	*philos_mt;
};

struct s_table
{
	t_philo			*philos;
	pthread_t		*tids;
	pthread_mutex_t	*forks;
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
	t_queue *queue;
};

struct s_meta
{
	t_args			args;
	t_clerk			clerk;
	t_table			table;
	pthread_mutex_t	start_mt;
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
	pthread_mutex_t	*fork[2];
	int				eat_cnt;
	uint64_t		last_meal;
	pthread_mutex_t	last_meal_mt;
	t_report		report;
	t_queue			*box;
	t_alert			*alert;
	pthread_mutex_t	*start_mt;
	t_args 			*args;
};

struct s_queue
{
	pthread_mutex_t	queue_mt;
	t_report    	*papers;
	int				front;
	int				rear;
	int				size;
};

#endif