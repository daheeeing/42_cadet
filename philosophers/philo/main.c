/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:32 by dapark            #+#    #+#             */
/*   Updated: 2023/03/20 22:17:30 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(long long start)
{
	long long			curr_t;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	curr_t = (curr.tv_sec * 1000000 + curr.tv_usec) / 1000;
	if (start == -1)
		return (curr_t);
	else
		return (curr_t - start);
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;

	info = malloc(sizeof(t_info));
	if (!info || init_info(argc, argv, info) != 0)
		return (1);
	philo = init_philo(info);
	if(!philos_born(info, philo))
		return (1);
	destroy_philos(philo);
	return (0);
}
