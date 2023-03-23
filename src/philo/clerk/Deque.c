/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:49 by sanghwal          #+#    #+#             */
/*   Updated: 2023/03/23 20:00:35 by jgo              ###   ########.fr       */
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
	deque->nodes = ft_calloc(sizeof(void *), deque->capacity);
	if (deque->nodes == NULL)
		return (NULL);
	deque->push_front = dq_push_front;
	deque->push_rear = dq_push_rear;
	deque->pop_front = dq_pop_front;
	deque->pop_rear = dq_pop_rear;
	deque->peek_front = dq_peek_front;
	deque->peek_rear = dq_peek_rear;
	return (deque);
}

void	dq_push_front(t_deque *deque, void *data)
{
	size_t	tmp;

	if (deque->use_size == 0)
		tmp = deque->front;
	else if (deque->front == 0)
		tmp = deque->capacity - 1;
	else
		tmp = deque->front - 1;
	deque->nodes[tmp] = data;
	deque->front = tmp;
	deque->use_size++;
}

void	dq_push_rear(t_deque *deque, void *data)
{
	size_t	tmp;

	if (deque->use_size == 0)
		tmp = deque->rear;
	else if (deque->rear == deque->capacity - 1)
		tmp = 0;
	else
		tmp = deque->rear + 1;
	deque->nodes[tmp] = data;
	deque->rear = tmp;
	deque->use_size++;
	return ;
}

void	*dq_pop_front(t_deque *deque)
{
	size_t	tmp;
	void	*data;

 	if (deque->front == deque->capacity - 1)
		tmp = 0;
	else
		tmp = deque->front + 1;
	data = deque->nodes[deque->front];
	if (data == NULL)
		return (NULL);
	if (deque->front != deque->rear)
		deque->front = tmp;
	deque->use_size--;
	return (data);
}

void	*dq_pop_rear(t_deque *deque)
{
	size_t	tmp;
	void	*data;

	if (deque->rear == 0)
		tmp = deque->capacity - 1;
	else
		tmp = deque->rear - 1;
	data = deque->nodes[deque->rear];
	if (deque->front != deque->rear)
		deque->rear = tmp;
	deque->use_size--;
	return (data);
}