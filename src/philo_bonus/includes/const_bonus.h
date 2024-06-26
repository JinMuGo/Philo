/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:59:01 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 10:08:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_BONUS_H
# define CONST_BONUS_H

# define FT 42
# define SC_ERR -1

# define FORK_SEM_NAME "/fork"
# define COUNTER_SEM_NAME "/counter"
# define PRINT_SEM_NAME "/print"
# define TERM_SEM_NAME "/terminate"

/*--------------  COLOR --------------*/
# define BOLD					"\e[1m"
# define MAGENTA				"\e[35m"
# define CYAN					"\e[36m"
# define GREEN					"\e[92m"
# define GRAY					"\e[90m"
# define RED					"\e[91m"
# define BLUE					"\e[94m"
# define RESET					"\e[0m"

/*-------------- OUTPUT.C --------------*/
# define FORK_MSG				"has taken a fork\n"
# define EAT_MSG				"is eating\n"
# define SLEEP_MSG				"is sleeping\n"
# define THINK_MSG				"is thinking\n"
# define DIED_MSG				"died\n"

/*-------------- ERROR.C --------------*/
# define ERR_ARGS_MSG			"❌ Incorrect number of arguments"
# define ERR_INVALID_ARGS_MSG	"❌ Invalid arguments"
# define ERR_ALLOC_MSG			"❌ Memory allocation failed"
# define ERR_INIT_PHILO_MSG		"❌ Error occured during philo initialized"
# define ERR_INIT_MUTEX_MSG		"❌ Error occured during mutex initialized"
# define ERR_THD_CREATE_MSG		"❌ Error occured during pthread create"
# define ERR_PROC_MSG			"❌ Error occured during process create"
# define ERR_SEM_OPEN_MSG		"❌ Error occured during named semaphore open"
# define ERR_GET_TIME_MSG		"❌ Error occured during gettime system call"

#endif