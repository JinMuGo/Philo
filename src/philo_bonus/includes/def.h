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
typedef struct s_terminate	t_terminate;
typedef struct s_meta_sem	t_meta_sem;
typedef struct s_sem		t_sem;

typedef union u_sem_val	t_u_sem_val;

/*-------------- UNION --------------*/
union u_sem_val
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
	sem_t			*queue_sem; // count_sem
};

struct s_sem
{
	t_u_sem_val	val;
	sem_t		*sem;
};

struct s_philo
{
	int				idx;
	t_args			*args;
	t_queue			*box;
	t_report		report;
	t_sem			eat_cnt; // count sem (main or self)
	t_sem			last_meal; // count sem (main or self)
	t_sem			*terminate; // binary sem
	sem_t			*fork_sem; // count sem의 pointer // 해당 세마포의 개수가 2 이상일 때만 잡게 하자.
	sem_t			*start_sem; // binary sem
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
	pid_t			*pids;
	sem_t			*fork_sem;
};

struct s_meta_sem
{
	t_sem			*terminate; // terminate값이 있어야하고 이에 접근하기 위한 sem_t가 ㅣㅆ어야 한다.
	sem_t			*start_sem; // bi
	sem_t			*terminate_sem; // count
	sem_t			*eat_cnt_sem; // count
	sem_t			*last_meal_sem; // count
};

struct s_meta
{
	t_args			args;
	t_clerk			clerk;
	t_table			table;
	t_meta_sem		sem;
};

#endif