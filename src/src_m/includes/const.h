/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:59:01 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 10:08:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define LEFT 0
# define RIGHT 1

/* output.c */
# define FORK_MSG "has taken a fork\n"
# define EAT_MSG "is eating\n"
# define SLEEP_MSG "is sleeping\n"
# define THINK_MSG "is thinking\n"
# define DIED_MSG "died\n"

/* error.c */
# define ERR_ARGS_MSG "❌ Incorrect number of arguments"
# define ERR_INVALID_ARGS_MSG "❌ Invalid arguments"
# define ERR_ALLOC_MSG "❌ Memory allocation failed"
# define ERR_INIT_PHILO_MSG "❌ error occured during philosopher initialized"
# define ERR_INIT_MUTEX_MSG "❌ error occured during mutex initialized"

/* color */
# define BOLD "\e[1m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define GREEN "\e[92m"
# define GRAY "\e[90m"
# define RED "\e[91m"
# define BLUE "\e[94m"
# define RESET "\e[0m"


#endif