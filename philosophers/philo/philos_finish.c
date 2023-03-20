/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:20:49 by dapark            #+#    #+#             */
/*   Updated: 2023/03/20 22:21:42 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_philos(t_philo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philos)
	{
		pthread_mutex_destroy(&philo->info->forks[i]);
		i++;
	}
	free(philo->info->forks);
	pthread_mutex_destroy(&philo->info->print_msg);
	pthread_mutex_destroy(&philo->info->must_eat_count);
	pthread_mutex_destroy(&philo->info->end_flag);
	return (0);
}
