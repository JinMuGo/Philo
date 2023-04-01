/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:46:48 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:29:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"

void	close_and_unlink_sem(sem_t *sem, const char *name)
{
	sem_close(sem);
	sem_unlink(name);
}

void	*post_and_return(sem_t *sem, void *val)
{
	sem_post(sem);
	return (val);
}
