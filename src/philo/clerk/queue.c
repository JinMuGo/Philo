/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:48:03 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 16:48:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"
#include "utils.h"

static bool	is_full(t_queue *queue)
{
	return ((queue->rear + 1) % queue->size == queue->front);
}

bool	is_empty(t_queue *queue)
{
	return (queue->rear == queue->front);
}

t_queue	*queue_init(int size)
{
	t_queue	*queue;

	queue = ft_calloc(1, sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	if (pthread_mutex_init(&queue->queue_mt, NULL))
		return (NULL);
	queue->size = size;
	queue->papers = ft_calloc(sizeof(t_report), size);
	if (queue->papers == NULL)
		return (NULL);
	return (queue);
}

bool	enqueue(t_queue *queue, t_report report)
{
	pthread_mutex_lock(&queue->queue_mt);
	if (is_full(queue))
	{
		pthread_mutex_unlock(&queue->queue_mt);
		return (false);
	}
	else
	{
		queue->rear = (queue->rear + 1) % queue->size;
		queue->papers[queue->rear] = report;
		pthread_mutex_unlock(&queue->queue_mt);
	}
	return (true);
}

t_report	*dequeue(t_queue *queue)
{
	t_report	*node;

	pthread_mutex_lock(&queue->queue_mt);
	if (is_empty(queue))
		return (unlock_and_return(&queue->queue_mt, NULL));
	else
	{
		queue->front = (queue->front + 1) % queue->size;
		node = &queue->papers[queue->front];
		if (node->num == 0)
			return (unlock_and_return(&queue->queue_mt, NULL));
		return (unlock_and_return(&queue->queue_mt, node));
	}
}
