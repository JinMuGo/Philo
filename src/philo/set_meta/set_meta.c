/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_meta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:17:17 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 15:10:15 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "set_meta.h"

void	set_meta(t_meta *meta, int ac, char **av)
{
	memset(meta, 0, sizeof(t_meta));
	set_args(&meta->args, ac, av);
	set_meta_mutex(&meta->mutex);
	set_clerk(&meta->clerk, meta->args.num_of_philo);
	set_alert(&meta->alert, meta->args.num_of_philo);
	set_table(&meta->table, meta->args.num_of_philo, meta);
}