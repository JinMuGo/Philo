/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:50:49 by jgo               #+#    #+#             */
/*   Updated: 2023/03/31 22:05:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_META_BONUS_H
# define SET_META_BONUS_H

/*------------- SET_META.C -------------*/
bool	set_meta(t_meta *meta, int ac, char **av);

/*------------- SET_ARGS.C -------------*/
bool	set_args(t_args *args, int ac, char **av);

/*------------- SET_TABLE.C -------------*/
bool	set_table(t_table *table, const int num_of_philo, t_meta *meta);

/*------------- SET_META_SEM.C -------------*/
bool	set_meta_sem(t_meta_sem *sem);

#endif