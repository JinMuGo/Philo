/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:16:30 by jgo               #+#    #+#             */
/*   Updated: 2023/03/30 18:04:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "state_control.h"

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

void	*post_and_return(sem_t *sem, void *val)
{
	sem_post(sem);
	return (val);
}

bool	wait_terminate_philo(t_meta *meta)
{
	int	i;
	int	exit_status;

	if (get_proc_state())
		return (false);
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		waitpid(meta->table.pids[i], &exit_status, 0);
		i++;
	}
	i = 0;
	while (i < meta->args.num_of_philo)
	{
		kill(meta->table.pids[i], SIGINT);
		i++;
	}
	printf(GREEN"Simulation End\n"RESET);
	return (true);
}

void	waiting_for_the_start(t_philo *philo)
{
	sem_wait(philo->start_sem);
	sem_post(philo->start_sem);
}
