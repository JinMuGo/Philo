/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:52:05 by jgo               #+#    #+#             */
/*   Updated: 2023/03/16 16:07:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"

t_bool prt_err(t_err err_num)
{
	char *msg 

	if (err_num == ERR_ARGS)
		msg = ERR_ARGS_MSG;
	if (err_num == ERR_ALLOC)
		msg = ERR_ALLOC_MSG;
	printf("%s\n", msg);
	return (FALSE);
}

