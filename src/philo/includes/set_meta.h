/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:50:49 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 14:36:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SET_META_H
# define SET_META_H

/* set_meta.c */
void	set_meta(t_meta *meta, int ac, char **av);

/* set_args.c */
bool	set_args(t_args *args, int ac, char **av);

/* set_table.c */
bool	set_table(t_table *table, const int num_of_philo, t_meta* meta);

/* set_clerk.c */
bool	set_clerk(t_clerk *clerk, const int num_of_philo);

/* set_meta_mutex.c */
bool	set_meta_mutex(t_meta_mutex *mutex);

/* set_alert.c */
bool set_alert(t_alert *alert, const int num_of_philo);

#endif