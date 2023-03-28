/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/03/28 10:57:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"

static void	clear_philos(t_philo *philos, const int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		pthread_mutex_destroy(&philos[i].eat_cnt.mt);
		pthread_mutex_destroy(&philos[i].last_meal.mt);
		pthread_mutex_destroy(&philos[i].terminate->mt);
		i++;
	}
	free(philos);
}

static void	clear_table(t_table *table, const int num_of_philo)
{
	if (table->forks)
		destroy_mutex_arr(table->forks, num_of_philo);
	if (table->tids)
		free(table->tids);
	if (table->philos)
		clear_philos(table->philos, num_of_philo);
}

static void	clear_meta_mutex(t_meta_mutex *mutex)
{
	if (mutex->terminate)
		free(mutex->terminate);
	pthread_mutex_destroy(&mutex->start_mt);
}

void	clear_all_asset(t_meta *meta)
{
	if (meta->clerk.queue && meta->clerk.queue->papers)
		free(meta->clerk.queue->papers);
	if (meta->clerk.queue)
		free(meta->clerk.queue);
	clear_table(&meta->table, meta->args.num_of_philo);
	clear_meta_mutex(&meta->mutex);
}
