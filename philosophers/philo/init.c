/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:57:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/20 23:14:09 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_info(int argc, char **argv, t_info *info)
{
	int		i;

	i = -1;
	if (argc != 5 && argc != 6)
		return (1);
	info->num_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	//info->time_start = get_time(-1, NULL);
	info->count_must_eat = 0;
	info->flag_end = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philos);
	if (!info->forks)
		return (1);
	if (pthread_mutex_init(&info->print_msg, NULL) || \
		pthread_mutex_init(&info->end_flag, NULL) || \
		pthread_mutex_init(&info->must_eat_count, NULL) || \
		pthread_mutex_init(&info->start_m, NULL))
		return (1);
	while (++i < info->num_philos)
	{
		if(pthread_mutex_init(&info->forks[i], NULL))
			return (1);
	}
	return (0);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * info->num_philos);
	if (!philo)
		return (NULL);
	while (i < info->num_philos)
	{
		philo[i].philo_num = i + 1;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % info->num_philos;
		philo[i].finish_eat = 0;
		philo[i].count_eat = 0;
		philo[i].info = info;
		i++;
	}
	return (philo);
}
