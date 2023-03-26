/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:52:05 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 17:04:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "state_control.h"

bool prt_err(t_err err_num, t_proc_state state)
{
	char *msg;

	msg = NULL;
	if (err_num == ERR_ARGS)
		msg = ERR_ARGS_MSG;
	else if (err_num == ERR_INVALID_ARGS)
		msg = ERR_INVALID_ARGS_MSG;
	else if (err_num == ERR_ALLOC)
		msg = ERR_ALLOC_MSG;
	else if (err_num == ERR_INIT_PHILO)
		msg = ERR_INIT_PHILO_MSG;
	else if (err_num == ERR_INIT_MUTEX)
		msg = ERR_INIT_MUTEX_MSG;
	else if (err_num == ERR_THD_CREATE)
		msg = ERR_THD_CREATE_MSG;
	else if (err_num == ERR_ENQUEUE)
		msg = ERR_ENQUEUE_MSG;
	printf("%s\n", msg);
	set_proc_state(state);
	return (false);
}