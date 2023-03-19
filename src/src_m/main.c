/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:34:52 by jgo               #+#    #+#             */
/*   Updated: 2023/03/19 10:19:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "defines.h"
#include "utils.h"
#include "error.h"

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat
int main(int ac, char **av)
{
	t_meta meta;

	if (ac < 5 || 6 < ac)
		return (prt_err(ERR_ARGS));
	init(&meta, ac, av);

	return (0);
}