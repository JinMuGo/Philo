/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:58:44 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 16:49:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

/*------------- QUEUE.C -------------*/
bool		is_empty(t_queue *queue);
t_queue		*queue_init(int size);
bool		enqueue(t_queue *queue, t_report report);
t_report	*dequeue(t_queue *queue);

#endif