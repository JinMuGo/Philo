/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:53:38 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:54:20 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

/*------------- MUTEX.C -------------*/
void	init_sem_struct_arr(sem_t *src, t_sem *dst, const int num_of_philo);
void	get_sem_value(t_sem *dst, t_sem *src, size_t size);
void	set_sem_value(t_sem *dst, size_t size, uint64_t option);
void	close_and_unlink_sem(sem_t *sem, const char *name);

#endif