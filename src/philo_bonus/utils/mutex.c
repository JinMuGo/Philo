/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:48 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 21:01:44 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "mutex.h"
#include "utils.h"

void	close_and_unlink_sem(sem_t *sem, const char *name)
{
	sem_close(sem);
	sem_unlink(name);
}

void	init_sem_struct_arr(sem_t *src, t_sem *dst, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		dst->sem = src;
		i++;
	}
}

// 값을 얻어오는 행동 int uint64_t bool
// 값을 쓰는 행동 int uint64_t boo
void	get_sem_value(t_sem *dst, t_sem *src, size_t size)
{
	sem_wait(src->sem);
	if (size == sizeof(bool))
		dst->val.b = src->val.b;
	else if (size == sizeof(int))
		dst->val.i = src->val.i;
	else
		dst->val.u = src->val.u;
	sem_post(src->sem);
}

void	set_sem_value(t_sem *dst, size_t size, uint64_t option)
{
	sem_wait(dst->sem);
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
	sem_post(dst->sem);
}
