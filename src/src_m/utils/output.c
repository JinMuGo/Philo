/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:42:09 by jgo               #+#    #+#             */
/*   Updated: 2023/03/18 10:36:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"

static char *get_state_msg(t_state state)
{
	if (state == FORK)
		return (FORK_MSG);
    else if (state == EAT)
		return (EAT_MSG);
	else if (state == SLEEP)
		return (SLEEP_MSG);
	else if (state == THINK)
		return (THINK_MSG);
	return (DIED_MSG);
}

void    output(uint64_t time, int num ,t_state state)
{
	// lock
    printf("%llu %d %s\n", time, num, get_state_msg(state));
	// 출력을 담당하는 thread를 하나 더 만들까? 
	// 그래서 그곳에서 메시지를 받아서 처리하는 형식? 나쁘지 않을듯?
	// unlock
}
