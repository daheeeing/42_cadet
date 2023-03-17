/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:32 by dapark            #+#    #+#             */
/*   Updated: 2023/03/17 23:29:28 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_time()
{
	size_t			curr_t;
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	curr_t = curr.tv_sec * 1000000 + curr.tv_usec;
	return (curr_t);
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
	check_philos_died(philo, info);
	destroy_philos(philo);
	return (0);
}
