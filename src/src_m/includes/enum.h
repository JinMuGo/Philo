/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:12:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 13:59:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_proc_state t_proc_state;
typedef enum e_philo_state t_philo_state;
typedef enum e_state_flag t_state_flag;
typedef enum e_err   t_err;
typedef enum e_bool  t_bool;

enum e_proc_state
{
	PROC_INIT,
	PROC_ERROR
};

enum e_state_flag
{
	GET,
	SET
};

enum e_philo_state 
{
	PHILO_INIT,
	PHILO_FORK,
	PHILO_EAT,
	PHILO_SLEEP,
	PHILO_THINK,
	PHILO_DIED
};

enum e_fork_state
{
	ON_TABLE,
	SOMEONE_USE
}

enum e_err
{
	ERR_ARGS,
	ERR_INVALID_ARGS,
	ERR_ALLOC,
	ERR_INIT_PHILO,
	ERR_INIT_MUTEX
};

enum e_bool
{
	TRUE,
	FALSE
};

#endif
