/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:32 by dapark            #+#    #+#             */
/*   Updated: 2023/03/24 17:03:45 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(long long flag, t_philo *philo)
{
	long long		curr_t;
	long long		ret;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	curr_t = (curr.tv_sec * 1000000 + curr.tv_usec) / 1000;
	if (flag == -1)
		return (curr_t);
	else
	{
		ret = curr_t - philo->info->time_start;
		return (ret);
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
	free(philo->info);
	return (0);
}

/*void	monitoring(t_philo *philo)
{
	int	i;
	int	end_flag;

	i = 0;
	pthread_mutex_lock(&philo->info->flag_end_m);
	end_flag = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	while (end_flag != 1)
	{
		while (philo[i].count_eat == philo->info->must_eat)
		{
			pthread_mutex_lock(&philo->info->flag_end_m);
			philo->info->flag_end = 1;
			pthread_mutex_unlock(&philo->info->flag_end_m);
			printf("%d\n", end_flag);
		}
		i++;
	}
	pthread_detach(philo->thread);
}*/

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;

	info = malloc(sizeof(t_info) * 1);
	if (!info || init_info(argc, argv, info) != 0)
		return (1);
	philo = init_philo(info);
	if (!philos_born(info, philo))
		return (1);
	destroy_philos(philo);
	return (0);
}
