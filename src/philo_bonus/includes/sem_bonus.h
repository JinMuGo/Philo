/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:19:24 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 20:29:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_BONUS_H
# define SEM_BONUS_H

void	close_and_unlink_sem(sem_t *sem, const char *name);
bool	post_and_return(sem_t *sem, bool val);

#endif