/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 11:10:43 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*------------- TIME.C -------------*/
uint64_t	get_micro_time(void);
void		take_a_nap_during_that_time(uint64_t that_time);

/*------------- UTILS.C -------------*/
int			char_to_uint64(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		*unlock_and_return(pthread_mutex_t *mutex, void *val);
bool		wait_terminate_philo(t_meta *meta);
void		waiting_for_the_start(t_philo *philo);

/*------------- OUTPUT.C -------------*/
void		output(t_report *report);

/*------------- CLEAR.C -------------*/
void		clear_all_asset(t_meta *meta);

#endif