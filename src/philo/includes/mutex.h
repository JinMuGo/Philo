/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:53:38 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 19:00:48 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

void    waiting_for_the_start(t_philo *philo);
void	get_mutexed_value(void *dst, void *val, pthread_mutex_t mutex);s
void	set_mutexed_value(void *dst, void *val, pthread_mutex_t mutex);

#endif