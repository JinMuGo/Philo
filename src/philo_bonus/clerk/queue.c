/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:48:03 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:46:21 by jgo              ###   ########.fr       */
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

static bool	is_empty(t_queue *queue)
{
	return (queue->rear == queue->front);
}

t_queue	*queue_init(int size, const int num_of_philo)
{
	t_queue	*queue;

	queue = ft_calloc(1, sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->queue_sem = sem_open(QUEUE_SEM_NAME, O_CREAT | O_EXCL, 0644, num_of_philo);
	if (queue->queue_sem == SEM_FAILED)
		return (NULL);
	queue->size = size;
	queue->papers = ft_calloc(sizeof(t_report), size);
	if (queue->papers == NULL)
		return (NULL);
	return (queue);
}

bool	enqueue(t_queue *queue, t_report report)
{
	sem_wait(queue->queue_sem);
	if (is_full(queue))
	{
		sem_post(queue->queue_sem);
		return (false);
	}
	else
	{
		queue->rear = (queue->rear + 1) % queue->size;
		queue->papers[queue->rear] = report;
		sem_post(queue->queue_sem);
	}
	return (true);
}

t_report	*dequeue(t_queue *queue)
{
	t_report	*node;

	sem_wait(queue->queue_sem);
	if (is_empty(queue))
		return (post_and_return(queue->queue_sem, NULL));
	else
	{
		queue->front = (queue->front + 1) % queue->size;
		node = &queue->papers[queue->front];
		if (node->num == 0)
			return (post_and_return(queue->queue_sem, NULL));
		return (post_and_return(queue->queue_sem, node));
	}
}
