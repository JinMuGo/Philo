/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:17:17 by jgo               #+#    #+#             */
/*   Updated: 2023/03/24 11:36:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "set_meta.h"

void	set_meta(t_meta *meta, int ac, char **av)
{
	memset(meta, 0, sizeof(t_meta));
	set_args(&meta->args, ac, av);
	set_clerk(&meta->clerk, meta->args.num_of_philo);
	set_table(&meta->table, meta->args.num_of_philo, meta->clerk.deque);
	set_meta_mutex(&meta->mutex);
}