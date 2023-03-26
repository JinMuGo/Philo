/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:27:12 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 22:26:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

/*  deque.c*/
t_deque		*deque_init(size_t size);
void		dq_push_rear(t_deque *deque, t_report data);
t_report	dq_pop_front(t_deque *deque);
#endif