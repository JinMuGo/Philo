/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:48 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 11:09:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "mutex.h"
#include "utils.h"

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

bool	init_mutex_arr(pthread_mutex_t *mutex, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(mutex + i, NULL))
			return (false);
		i++;
	}
	return (true);
}

bool	init_mutex_struct_arr(t_mutex *mutex, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_mutex_init(&mutex[i].mt, NULL))
			return (false);
		i++;
	}
	return (true);
}

// 값을 얻어오는 행동 int uint64_t bool
// 값을 쓰는 행동 int uint64_t boo
void	get_mutex_value(t_mutex *dst, t_mutex *src, size_t size)
{
	pthread_mutex_lock(&src->mt);
	if (size == sizeof(bool))
		dst->val.b = src->val.b;
	else if (size == sizeof(int))
		dst->val.i = src->val.i;
	else
		dst->val.u = src->val.u;
	pthread_mutex_unlock(&src->mt);
}

void	set_mutex_value(t_mutex *dst, size_t size, uint64_t option)
{
	pthread_mutex_lock(&dst->mt);
	if (size == sizeof(bool))
		dst->val.b = true;
	else if (size == sizeof(int))
		dst->val.i++;
	else
	{
		if (option)
			dst->val.u = option;
		else
			dst->val.u = get_micro_time();
	}
	pthread_mutex_unlock(&dst->mt);
}
