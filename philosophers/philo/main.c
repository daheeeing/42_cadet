/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:32 by dapark            #+#    #+#             */
/*   Updated: 2023/03/31 21:07:15 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(long long flag, t_philo *philo)
{
	long long		curr_time;
	long long		ret;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	curr_time = (curr.tv_sec * 1000000 + curr.tv_usec) / 1000;
	if (flag == -1)
		return (curr_time);
	else
	{
		ret = curr_time - philo->info->time_start;
		return (ret);
	}
}

void	ft_usleep(long long stop, t_philo *philo)
{
	long long	start;
	int			flag_end;

	start = get_time(0, philo);
	pthread_mutex_lock(&philo->info->flag_end_m);
	flag_end = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	while (!flag_end)
	{
		pthread_mutex_lock(&philo->info->flag_end_m);
		flag_end = philo->info->flag_end;
		pthread_mutex_unlock(&philo->info->flag_end_m);
		if (get_time(0, philo) - start >= stop)
			break ;
		usleep(100);
	}
}

int	destroy_philos(t_philo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philos)
	{
		pthread_mutex_destroy(&philo->info->forks_m[i]);
		i++;
	}
	free(philo->info->forks_m);
	pthread_mutex_destroy(&philo->info->print_msg_m);
	pthread_mutex_destroy(&philo->info->flag_end_m);
	pthread_mutex_destroy(&philo->info->count_must_eat_m);
	pthread_mutex_destroy(&philo->info->check_m);
	free(philo->info);
	free(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;

	info = malloc(sizeof(t_info) * 1);
	if (!info || init_info(argc, argv, info) != 0)
		return (1);
	philo = init_philo(info);
	if (philos_born(info, philo) != 0)
		return (1);
	destroy_philos(philo);
	return (0);
}
