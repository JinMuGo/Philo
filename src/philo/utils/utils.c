/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:16:30 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 15:13:14 by jgo              ###   ########.fr       */
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

	if (get_proc_state() == SET_ERROR)
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
	if (sign == -1 || str[i] != '\0')
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

void	destroy_mutex_arr(pthread_mutex_t *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(arr + i);
		i++;
	}
	free(arr);
}

void	clear_philos(t_philo *philos, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_destroy(&philos[i].last_meal_mt);
		i++;
	}
}

void	clear_table(t_table *table, const int num_of_philo)
{
	if (table->forks)
		destroy_mutex_arr(table->forks, num_of_philo);
	if (table->tids)
		free(table->tids);
	if (table->philos)
		clear_philos(table->philos, num_of_philo);
}

void	clear_alert(t_alert *alert, const int num_of_philo)
{
	if (alert->terminate)
		free(alert->terminate);
	if (alert->terminate_mt)
		destroy_mutex_arr(alert->terminate_mt, num_of_philo);
	if (alert->philos_mt)
		destroy_mutex_arr(alert->philos_mt, num_of_philo);
}

void	clear_all_asset(t_meta *meta)
{
	if (meta->clerk.queue->papers)
		free(meta->clerk.queue->papers);
	if (meta->clerk.queue)
		free(meta->clerk.queue);
	clear_table(&meta->table, meta->args.num_of_philo);
	clear_alert(&meta->alert, meta->args.num_of_philo);
}

void	*unlock_and_return(pthread_mutex_t *mutex, void *val)
{
	pthread_mutex_unlock(mutex);
	return (val);
}