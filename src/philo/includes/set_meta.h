/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:50:49 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 19:28:44 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SET_META_H
# define SET_META_H

/* set_meta.c */
void	set_meta(t_meta *meta, int ac, char **av);

/* set_args.c */
bool	set_args(t_args *args, int ac, char **av);

/* set_table.c */
bool	set_table(t_table *table, const int num_of_philo, t_deque *deque);

/* set_clerk.c */
bool	set_clerk(t_clerk *clerk, const int num_of_philo);

#endif