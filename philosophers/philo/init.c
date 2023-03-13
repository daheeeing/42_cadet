/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:57:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/13 22:25:43 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_info(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (0);
	info->num_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	return (1);
}

t_philo	init_philo(t_info *info)
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
		if (i != 0)
			philo->right_fork = i;
		philo->left_fork = i + 1;
		philo->end_eat = info->time_start;
		philo->count_eat = 0;
		i++;
	}
	return (philo);
}
