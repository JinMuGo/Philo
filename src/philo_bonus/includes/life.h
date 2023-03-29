/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:07:46 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 20:22:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

/*-------------- EAT.C --------------*/
void		philo_eat(t_philo *philo);

/*------------- FORK.C --------------*/
void		philo_take_left_fork(t_philo *philo);
void		philo_take_right_fork(t_philo *philo);

/*------------- THINK.C -------------*/
void		philo_think(t_philo *philo);

/*------------- SLEEP.C -------------*/
void		philo_sleep(t_philo *philo);

/*----------- BEGIN_LIFE.C -----------*/
t_report	write_report(t_philo *philo, t_philo_state state);
void    	begin_life(t_philo	*philo);

/*---- WATCH_THEIR_LIVES.C ----*/
bool		watch_their_lives(t_meta *meta);

/*---------- BE_BORN_PHILO.C ----------*/
bool		be_born_philo(t_meta *meta);

#endif