/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/17 23:43:14 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_born(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)philos_activities, (t_philo *) &philo[i]))
			return (1);
		usleep(50);
		i++;
	}
	/*i = 0;
	while (i < info->num_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}*/
	return (0);
}

void	*philos_eat(t_philo *philo)
{
	int	lfork;
	int	rfork;

	rfork = pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	lfork = pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_philo_msg("has taken a fork", philo);
	philo->finish_eat = get_time();
	print_philo_msg("is eating", philo);
	philo->count_eat++;
	check_must_eat(philo);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	return (NULL);
}

void	*philos_sleep(t_philo *philo)
{
	print_philo_msg("is sleeping", philo);
	return (NULL);
}

void	*philos_think(t_philo *philo)
{
	print_philo_msg("is thinking", philo);
	return (NULL);
}

void	*philos_activities(t_philo *philo)
{
	if (philo->philo_num % 2 != 0)
		usleep(1000);
	while(1)
	{
		philos_eat(philo);
		philos_sleep(philo);
		philos_think(philo);
	}
	return (NULL);
}
