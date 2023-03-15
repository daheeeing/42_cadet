/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:32 by dapark            #+#    #+#             */
/*   Updated: 2023/03/15 17:47:16 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	*threads;

	info = malloc(sizeof(t_info));
	if (!info || !init_info(info))
		return (1);
	philo = init_philo(info);
	if(!philos_born(info, philo))
		return (1);
	mornitoring();
	kill_threads(philo);
}
