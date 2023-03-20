/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/20 22:32:17 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_born(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (info->num_philos == 1)
		pthread_create(&philo[i].thread, NULL, (void *)only_one_philo, (t_philo *) &philo[i]);
	else
	{
		while (i < info->num_philos)
		{
			if (pthread_create(&philo[i].thread, NULL, (void *)philos_activities, (t_philo *) &philo[i]))
				return (1);
			i++;
		}
	}	
	i = 0;
	while (i < info->num_philos)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}

void	philos_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_philo_msg("has taken a fork", philo);
	print_philo_msg("is eating", philo);
	philo->finish_eat = get_time(philo->info->time_start);
	philo->count_eat++;
	if (philo->info->must_eat != -1)
		check_must_eat(philo);
	ft_usleep(philo->info->time_eat, philo->info);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	return ;
}

void	*philos_activities(t_philo *philo)
{
	if (philo->philo_num % 2 != 0)
		usleep(1000);
	while(philo->info->flag_end != 1)
	{
		philos_eat(philo);
		print_philo_msg("is sleeping", philo);
		ft_usleep(philo->info->time_sleep, philo->info);
		print_philo_msg("is thinking", philo);
	}
	return (NULL);
}
