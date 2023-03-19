/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:16:30 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 11:03:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"
#include "state_control.h"

uint64_t	char_to_uint64(const char *str)
{
	uint64_t	result;
	int			sign;
	int			i;

	if (get_proc_state() == PROC_ERROR)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (sign == -1)
	{
		set_proc_state(PROC_ERROR);
		return (0);
	}
	return (result);
}

t_bool	check_args(t_meta *meta)
{
	printf("%d\n",(meta->num_of_philo >= 0 & meta->time_to_die >= 0 & meta->time_to_eat >= 0 &	meta->time_to_sleep >= 0));
	return (TRUE);
}

// void	clear_all_asset(t_meta *meta)
// {
	
// }