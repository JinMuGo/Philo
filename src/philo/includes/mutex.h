/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:53:38 by jgo               #+#    #+#             */
/*   Updated: 2023/03/28 10:58:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

bool	init_mutex_arr(pthread_mutex_t *mutex, const int num_of_philo);
bool	init_mutex_struct_arr(t_mutex *mutex, const int num_of_philo);

void	waiting_for_the_start(t_philo *philo);
void	get_mutex_value(t_mutex *dst, t_mutex *src, size_t size);
void	set_mutex_value(t_mutex *dst, size_t size, uint64_t option);

#endif