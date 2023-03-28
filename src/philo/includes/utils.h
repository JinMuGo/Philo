/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/28 11:04:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* TIME.C */
uint64_t	get_ms_time(void);
void		take_a_nap_during_that_time(uint64_t that_time);

/* UTILS.C */
int			char_to_uint64(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		*unlock_and_return(pthread_mutex_t *mutex, void *val);
void		destroy_mutex_arr(pthread_mutex_t *arr, int size);
void		wait_terminate_philo(t_meta *meta);

/* OUTPUT.C */
void		output(t_report *report);

/* CLEAR.C */
void		clear_all_asset(t_meta *meta);

#endif