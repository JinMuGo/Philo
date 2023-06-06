/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:29:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

/*------------- TIME.C -------------*/
uint64_t	get_micro_time(void);
void		take_a_nap_during_that_time(uint64_t that_time);

/*------------- UTILS.C -------------*/
int			char_to_uint64(const char *str);
void		*ft_calloc(size_t count, size_t size);
bool		wait_terminate_philo(t_meta *meta);

/*------------- OUTPUT.C -------------*/
void		output(sem_t *print_sem, t_report report);

/*------------- CLEAR.C -------------*/
void		clear_all_asset(t_meta *meta);

/*--------- MAKE_PHILO_SEM_NAME.C --------*/
char		*make_philo_sem_name(int n);

#endif