/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:07:46 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 20:28:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_BONUS_H
# define LIFE_BONUS_H

/*-------------- EAT.C --------------*/
void		philo_eat(t_philo *philo);

/*------------- FORK.C --------------*/
void		philo_take_fork(t_philo *philo);

/*------------- THINK.C -------------*/
void		philo_think(t_philo *philo);

/*------------- SLEEP.C -------------*/
void		philo_sleep(t_philo *philo);

/*----------- BEGIN_LIFE.C -----------*/
t_report	write_report(t_philo *philo, t_philo_state state);
bool		begin_life(t_philo	*philo, const int idx);

/*---- WATCH_PHILO_LIVES.C ----*/
void		*watch_philo_lives(void *arg);

/*---------- BE_BORN_PHILO.C ----------*/
bool		be_born_philo(t_meta *meta);

#endif