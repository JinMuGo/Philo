/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:16:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/24 11:22:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"

static bool dead_receiver(t_state_flag flag, bool arg)
{
	static bool	someone_dead;
	
	if (flag == GET)
		return (someone_dead);
	else if (flag == SET)
		someone_dead = arg;
	return (true);
}

bool get_dead_report(void)
{
	return (dead_receiver(GET, 0));
}

void set_dead_report(bool arg)
{
	dead_receiver(SET, arg);
}