/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clerk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:25:02 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 16:41:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "deque.h"
#include "error.h"

bool	set_clerk(t_clerk *clerk, const int num_of_philo)
{
	clerk->deque = deque_init(num_of_philo * 4);
	if (clerk->deque == NULL)
		return (prt_err(ERR_ALLOC, SET_ERROR));
	return (true);
}