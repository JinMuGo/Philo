/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/22 12:06:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"

// 1 초(second) = 1,000 밀리초(millisecond) = 1,000,000 마이크로초(microsecond)
//  마이크로초와 밀리초는 1,000배 관계이며, 밀리초와 초는 1,000배 관계입니다. 
uint64_t get_ms_time(void)
{
	static struct timeval	tv;

	if (sc_err(gettimeofday(&tv, NULL)))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}