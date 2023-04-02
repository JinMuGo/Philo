/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/29 09:23:03 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"

// 1 초(second) = 1,000 밀리초(millisecond) = 1,000,000 마이크로초(microsecond)
// 마이크로초와 밀리초는 1,000배 관계이며, 밀리초와 초는 1,000배 관계입니다. 
uint64_t	get_micro_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void	take_a_nap_during_that_time(uint64_t that_time)
{
	const uint64_t	start_time = get_micro_time();
	const uint64_t	end_time = start_time + that_time;

	usleep(that_time * 0.9);
	while (true)
	{
		usleep(FT);
		if (get_micro_time() >= end_time)
			return ;
	}
}
