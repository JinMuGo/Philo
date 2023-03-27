/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:34:52 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 18:28:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "error.h"
#include "set_meta.h"
#include "life.h"
#include "state_control.h"
#include "queue.h"

int	main(int ac, char **av)
{
	t_meta	meta;

	if (ac < 5 || 6 < ac)
		return (prt_err(ERR_ARGS, SET_ERROR));
	if (!set_meta(&meta, ac, av))
		return (EXIT_FAILURE);
	be_born_philo(&meta);
	life_goes_on_until_death(&meta);
	wait_terminate_philo(&meta);
	clear_all_asset(&meta);
	if (get_proc_state())
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
