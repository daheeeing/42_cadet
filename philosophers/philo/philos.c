/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/19 22:34:56 by daheepark        ###   ########.fr       */
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
	return (0);
}

void	*philos_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_philo_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->eat_meal);
	philo->finish_eat = get_time();
	print_philo_msg("is eating", philo);
	pthread_mutex_unlock(&philo->info->eat_meal);
	philo->count_eat++;
	check_must_eat(philo);
	usleep(1);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	return (NULL);
}

void	*philos_activities(t_philo *philo)
{
	if (philo->philo_num % 2 != 0 && philo->count_eat > 1)
		ft_usleep(10000, philo->info);
	while(philo->info->flag_end != 1)
	{
		philos_eat(philo);
		print_philo_msg("is sleeping", philo);
		ft_usleep(philo->info->time_sleep, philo->info);
		print_philo_msg("is thinking", philo);
	}
	return (NULL);
}
