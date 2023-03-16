/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/16 15:35:55 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* init.c */
t_bool init(t_meta *meta, int ac, char **av);

/* error.c */
int prt_err(t_err err_num);

/* time.c */
uint64_t get_ms_time(void);

/* utils.c */
int	ft_atoi(const char *str);

#endif