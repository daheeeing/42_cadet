/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:52:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/13 21:48:43 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

typedef	struct s_info
{
	int		num_philos;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	int		flag_must_eat;
	size_t	time_start;
	pthread_mutex_t	*fork;
	pthread_mutex_t print_msg;
} t_info;

typedef struct s_philo
{
	int		right_fork;
	int		left_fork;
	int		philo_num;
	int		count_eat;
	size_t	end_eat;
	t_info	*info;
}	t_philo;

#endif
