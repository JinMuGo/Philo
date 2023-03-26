/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:07:46 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 10:34:39 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

t_report	write_report(t_philo *philo, t_philo_state state);
void *begin_life(void *philo_arg);

bool be_born_philo(t_meta *meta);

void	philo_eat(t_philo *philo);
void	philo_take_left_fork(t_philo *philo);
void	philo_take_right_fork(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
#endif