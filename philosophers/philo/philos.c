/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:56:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/15 18:08:38 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philos_born(t_info *info, t_philo *philo)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * info->num_philos);
	if (!threads)
		return (1);
	while (i < info->num_philos)
	{
		if (pthread_create(&threads[i], NULL, philos_activities, &philo[i]))
			return (1);
		usleep(50);
		i++;
	}
	return (0);
}

void	*philos_eat(t_philo *philo)
{
	int		lfork;
	int		rfork;
	t_time	start_t;

	rfork = pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	print_philo_msg(FORK, philo);
	lfork = pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_philo_msg(FORK, philo);
	print_philo_msg(EAT, philo);
	philo->finish_eat = gettimeofday(&start_t, NULL);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}

void	*philos_sleep(t_philo *philo)
{
	
}

void	*philos_think(t_philo *philo)
{
	
}

void	*philos_activities(void *arg)
{
	while(1)
	{
		philos_eat((t_philo *)arg);
		philos_sleep((t_philo *)arg);
		philos_think((t_philo *)arg);
	}
	return ;
}
