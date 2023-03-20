/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:20:49 by dapark            #+#    #+#             */
/*   Updated: 2023/03/19 22:35:35 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_philos(t_philo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philos)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
	i = 0;
	while (i < philo->info->num_philos)
	{
		pthread_mutex_destroy(&philo->info->forks[i]);
		i++;
	}
	free(philo->info->forks);
	return (0);
}
