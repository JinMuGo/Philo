/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:50:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/23 15:31:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "deque.h"

void	*dq_peek_front(const t_deque *deque)
{
	if (deque->use_size)
		return (deque->nodes[deque->front]);
	else
		return (NULL);
}

void	*dq_peek_rear(const t_deque *deque)
{
	if (deque->use_size)
		return (deque->nodes[deque->rear]);
	else
		return (NULL);
}

void	dq_free(const t_deque *deque)
{
	size_t	i;

	i = 0;
	while (i < deque->use_size)
	{
		free(deque->nodes[(i + deque->front) % deque->capacity]);
		i++;
	}
	free(deque->nodes);
	free((void *)deque);
}

void	dq_clear(t_deque *deque)
{
	while (deque->use_size > 0)
		deque->pop_front(deque);
}
