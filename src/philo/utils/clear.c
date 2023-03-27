/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:46 by jgo               #+#    #+#             */
/*   Updated: 2023/03/27 18:10:33 by jgo              ###   ########.fr       */
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
		pthread_mutex_destroy(&philos[i].last_meal_mt);
		i++;
	}
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

static void	clear_alert(t_alert *alert, const int num_of_philo)
{
	if (alert->terminate)
		free(alert->terminate);
	if (alert->terminate_mt)
		destroy_mutex_arr(alert->terminate_mt, num_of_philo);
	if (alert->philos_mt)
		destroy_mutex_arr(alert->philos_mt, num_of_philo);
}

void	clear_all_asset(t_meta *meta)
{
	if (meta->clerk.queue->papers)
		free(meta->clerk.queue->papers);
	if (meta->clerk.queue)
		free(meta->clerk.queue);
	clear_table(&meta->table, meta->args.num_of_philo);
	clear_alert(&meta->alert, meta->args.num_of_philo);
}
