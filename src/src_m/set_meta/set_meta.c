/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:17:17 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 11:35:51 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "set_meta.h"

void	set_meta(t_meta *meta, int ac, char **av)
{
	memset(meta, 0, sizeof(t_meta));
	set_args(&meta->args, ac, av);
	set_table(&meta->table, meta->args.num_of_philo);
	set_mutex(&meta->mutex, meta->args.num_of_philo);
}