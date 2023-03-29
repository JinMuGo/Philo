/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:16:30 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 11:10:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "state_control.h"
#include "mutex.h"

uint64_t	char_to_uint64(const char *str)
{
	uint64_t	result;
	int			sign;
	int			i;

	if (get_proc_state())
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
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	if (sign == -1 || str[i] != '\0' || result == 0)
	{
		set_proc_state(SET_ERROR);
		return (0);
	}
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(size * count);
	if (dst)
		memset(dst, 0, size * count);
	else
		return (NULL);
	return (dst);
}

void	*unlock_and_return(pthread_mutex_t *mutex, void *val)
{
	pthread_mutex_unlock(mutex);
	return (val);
}

bool	wait_terminate_philo(t_meta *meta)
{
	int	i;

	if (get_proc_state())
		return (false);
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		set_mutex_value(meta->mutex.terminate + i, sizeof(bool), 0);
		i++;
	}
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		pthread_join(meta->table.tids[i], NULL);
		i++;
	}
	printf(GREEN"Simulation End\n"RESET);
	return (true);
}

void	waiting_for_the_start(t_philo *philo)
{
	pthread_mutex_lock(philo->start_mt);
	pthread_mutex_unlock(philo->start_mt);
}
