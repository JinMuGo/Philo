/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:12:47 by jgo               #+#    #+#             */
/*   Updated: 2023/04/02 08:07:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_BONUS_H
# define ENUM_BONUS_H

/*-------------- TYPEDEF --------------*/
typedef enum e_proc_state	t_proc_state;
typedef enum e_philo_state	t_philo_state;
typedef enum e_fork_state	t_fork_state;
typedef enum e_state_flag	t_state_flag;
typedef enum e_err			t_err;
typedef enum e_hand			t_hand;

/*-------------- ENUM --------------*/
enum e_proc_state
{
	DEFAULT,
	SET_ERROR,
	THD_ERROR,
	QUE_ERROR,
	TIME_ERROR,
	PROC_ERROR,
	SEM_ERROR
};

enum e_state_flag
{
	GET,
	SET
};

enum e_philo_state
{
	PHILO_FORK,
	PHILO_EAT,
	PHILO_SLEEP,
	PHILO_THINK
};

enum e_fork_state
{
	ON_TABLE,
	ON_HAND
};

enum e_err
{
	ERR_ARGS,
	ERR_INVALID_ARGS,
	ERR_ALLOC,
	ERR_INIT_PHILO,
	ERR_INIT_MUTEX,
	ERR_THD_CREATE,
	ERR_PROC_CREATE,
	ERR_ENQUEUE,
	ERR_SEM_OPEN,
	ERR_GET_TIME
};

enum e_hand
{
	L,
	R
};

#endif