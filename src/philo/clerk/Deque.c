/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:49 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/26 13:28:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "deque.h"
#include "utils.h"

t_deque	*deque_init(size_t size)
{
	t_deque	*deque;

	deque = ft_calloc(1, sizeof(t_deque));
	if (deque == NULL)
		return (NULL);
	if (pthread_mutex_init(&deque->queue_mt, NULL))
		return (NULL);
	deque->capacity = size;
	deque->front = 0;
	deque->rear = 0;
	deque->use_size = 0;
	deque->papers = ft_calloc(sizeof(t_report), deque->capacity);
	if (deque->papers == NULL)
		return (NULL);
	deque->push_rear = dq_push_rear;
	deque->pop_front = dq_pop_front;
	return (deque);
}

void	dq_push_rear(t_deque *deque, t_report data)
{
	size_t	tmp;

	pthread_mutex_lock(&deque->queue_mt);
	if (deque->use_size == 0)
		tmp = deque->rear;
	else if (deque->rear == deque->capacity - 1)
		tmp = 0;
	else
		tmp = deque->rear + 1;
	deque->papers[tmp] = data;
	deque->rear = tmp;
	deque->use_size++;
	pthread_mutex_unlock(&deque->queue_mt);
}

t_report	dq_pop_front(t_deque *deque)
{
	t_report	data;
	size_t		tmp;

	pthread_mutex_lock(&deque->queue_mt);
 	if (deque->front == deque->capacity - 1)
		tmp = 0;
	else
		tmp = deque->front + 1;
	data = deque->papers[deque->front];
	deque->papers[deque->front].num = 0;
	if (deque->front != deque->rear)
		deque->front = tmp;
	deque->use_size--;
	pthread_mutex_unlock(&deque->queue_mt);
	return (data);
}
