/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clerk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:25:02 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 16:43:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "queue.h"
#include "error.h"

bool	set_clerk(t_clerk *clerk, const int num_of_philo)
{
	clerk->queue = queue_init(num_of_philo * 10);
	if (clerk->queue == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	return (true);
}
