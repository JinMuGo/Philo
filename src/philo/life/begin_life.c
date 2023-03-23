/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:06:24 by jgo               #+#    #+#             */
/*   Updated: 2023/03/23 20:40:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "err.h"

// 홀수 : 밥 -> 잠 -> 생각 
// 한명일 때도 생각해줄 것. 한명일 때는 밥을 먹으려고 계속 다른 포크를 들려고하다가 죽어야함. 
void	odd_philo(t_philo *philo)
{
	
}

// 짝수 : 생각 -> 밥 -> 잠
void	even_philo(t_philo *philo)
{
	
}

void *begin_life(void *philo_arg)
{
	t_philo *philo;

	philo = philo_arg;
	philo->report.num = philo->idx + 1;
	if (philo->report.num & 1)
		odd_philo(philo);
	else
		even_philo(philo);
	return (NULL);
}