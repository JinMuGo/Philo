/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:46:23 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 14:41:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"

static t_proc_state proc_state_receiver(t_state_flag flag, t_proc_state arg)
{
	static t_proc_state state;

	if (flag == SET)
		state = arg;
	return (state);
}

t_proc_state get_proc_state()
{
	return (proc_state_receiver(GET, 0));
}

void set_proc_state(t_proc_state arg)
{
	proc_state_receiver(SET, arg);
}
