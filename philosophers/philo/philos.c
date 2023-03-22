/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/22 21:43:11 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_born(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	info->time_start = get_time(-1, NULL);
	if (info->num_philos == 1)
		pthread_create(&philo[i].thread, NULL, \
		(void *)only_one_philo, (t_philo *) &philo[i]);
	else
	{
		while (i < info->num_philos)
		{
			if (pthread_create(&philo[i].thread, NULL, \
			(void *)philos_activities, (t_philo *) &philo[i]))
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
	pthread_mutex_lock(&philo->info->forks_m[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->forks_m[philo->right_fork]);
	print_philo_msg("has taken a fork", philo);
	print_philo_msg("is eating", philo);
	philo->finish_eat = get_time(0, philo);
	philo->count_eat++;
	ft_usleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(&philo->info->forks_m[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks_m[philo->left_fork]);
	return ;
}

void	*philos_activities(t_philo *philo)
{
	int	flag_end;

	if (philo->philo_num % 2 != 0)
		usleep(1000);
	pthread_mutex_lock(&philo->info->flag_end_m);
	flag_end = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	while (flag_end != 1)
	{
		philos_eat(philo);
		if (philo->count_eat == philo->info->must_eat)
			break ;
		print_philo_msg("is sleeping", philo);
		ft_usleep(philo->info->time_sleep, philo);
		print_philo_msg("is thinking", philo);
		pthread_mutex_lock(&philo->info->flag_end_m);
		flag_end = philo->info->flag_end;
		pthread_mutex_unlock(&philo->info->flag_end_m);
	}
	return (NULL);
}
