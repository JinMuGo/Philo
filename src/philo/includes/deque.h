/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:27:12 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 15:31:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

/*  deque.c*/
t_deque		*deque_init(size_t size);
void		dq_push_front(t_deque *deque, void *data);
void		dq_push_rear(t_deque *deque, void *data);
void		*dq_pop_front(t_deque *deque);
void		*dq_pop_rear(t_deque *deque);
void		*dq_peek_front(const t_deque *deque);
void		*dq_peek_rear(const t_deque *deque);
void		dq_free(const t_deque *deque);
void		dq_clear(t_deque *deque);

#endif