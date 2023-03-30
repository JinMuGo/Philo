/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:17:17 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 16:27:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "set_meta.h"

bool	set_meta(t_meta *meta, int ac, char **av)
{
	memset(meta, 0, sizeof(t_meta));
	if (!set_args(&meta->args, ac, av))
		return (false);
	if (!set_meta_sem(&meta->sem, meta->args.num_of_philo))
		return (false);
	if (!set_clerk(&meta->clerk, meta->args.num_of_philo))
		return (false);
	if (!set_table(&meta->table, meta->args.num_of_philo, meta))
		return (false);
	return (true);
}
