/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 10:59:24 by jgo              ###   ########.fr       */
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
void		*post_and_return(sem_t *sem, void *val);
bool		wait_terminate_philo(t_meta *meta);

/*------------- OUTPUT.C -------------*/
void		output(sem_t *print_sem, t_report report);

/*------------- CLEAR.C -------------*/
void		clear_all_asset(t_meta *meta);

#endif