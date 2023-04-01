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
typedef struct s_report		t_report;
typedef struct s_terminate	t_terminate;
typedef struct s_meta_sem	t_meta_sem;

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

struct s_philo
{
	int				idx;
	pid_t			*pids;
	t_args			*args;
	t_report		report;
	int				eat_cnt;
	uint64_t		last_meal;
	pthread_t		moniter_thd;
	sem_t			*fork_sem;
	sem_t			*print_sem;
	sem_t			*counter_sem;
	sem_t			*terminate_sem;
	sem_t			*last_meal_sem;
	char			*philo_sem_name;
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

struct s_table
{
	t_philo			philo;
	pid_t			*pids;
	sem_t			*fork_sem;
};

struct s_meta_sem
{
	sem_t	*counter_sem;
	sem_t	*print_sem;
	sem_t	*terminate_sem;
};

struct s_meta
{
	t_args			args;
	t_table			table;
	t_meta_sem		sem;
	pthread_t		meal_counter;
};

#endif