/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:34:52 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 23:24:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "def_bonus.h"
#include "utils_bonus.h"
#include "error_bonus.h"
#include "set_meta_bonus.h"
#include "life_bonus.h"
#include "state_control_bonus.h"

int	main(int ac, char **av)
{
	t_meta	meta;

	if (ac < 5 || 6 < ac)
		return (prt_err(ERR_ARGS, SET_ERROR));
	if (!set_meta(&meta, ac, av))
		return (EXIT_FAILURE);
	if (!be_born_philo(&meta))
		return (EXIT_FAILURE);
	if (!wait_terminate_philo(&meta))
		return (EXIT_FAILURE);
	clear_all_asset(&meta);
	return (EXIT_SUCCESS);
}
