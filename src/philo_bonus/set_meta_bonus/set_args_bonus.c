/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:20:10 by jgo               #+#    #+#             */
/*   Updated: 2023/03/22 20:14:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "error_bonus.h"
#include "utils_bonus.h"
#include "state_control_bonus.h"

bool	set_args(t_args *args, int ac, char **av)
{
	args->num_of_philo = char_to_uint64(av[1]);
	args->time_to_die = char_to_uint64(av[2]) * 1000;
	args->time_to_eat = char_to_uint64(av[3]) * 1000;
	args->time_to_sleep = char_to_uint64(av[4]) * 1000;
	if (ac == 6)
		args->num_of_must_eat = char_to_uint64(av[5]);
	else
		args->num_of_must_eat = -1;
	if (get_proc_state() == SET_ERROR)
		return (prt_err(ERR_INVALID_ARGS, SET_ERROR));
	return (true);
}
