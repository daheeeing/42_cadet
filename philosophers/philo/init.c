/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:57:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/24 17:16:55 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_info(int argc, char **argv, t_info *info)
{
	int	i;

	i = -1;
	if (argc != 5 && argc != 6)
		return (1);
	info->num_philos = check_int(argv[1]);
	info->time_die = check_int(argv[2]);
	info->time_eat = check_int(argv[3]);
	info->time_sleep = check_int(argv[4]);
	info->must_eat = -1;
	if (argc == 6)
		info->must_eat = check_int(argv[5]);
	info->flag_end = 0;
	if (info->num_philos < 1 || info->time_die < 0 || \
		info->time_eat < 0 || info->time_sleep < 0 || \
		info->must_eat == 0)
		return (1);
	info->forks_m = malloc(sizeof(pthread_mutex_t) * info->num_philos);
	if (!info->forks_m)
		return (1);
	if (mutex_init_check_error(info) != 0)
		return (1);
	return (0);
}

int	mutex_init_check_error(t_info *info)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&info->print_msg_m, NULL) || \
		pthread_mutex_init(&info->flag_end_m, NULL))
		return (1);
	while (++i < info->num_philos)
	{
		if (pthread_mutex_init(&info->forks_m[i], NULL))
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
