/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:07:00 by dapark            #+#    #+#             */
/*   Updated: 2023/03/20 15:48:58 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	long	np;
	long	ret;

	np = 1;
	ret = 0;
	while (*str == '\t' || *str == '\r' || *str == '\v'
		|| *str == ' ' || *str == '\f' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			np *= -1;
		str++;
	}
	while ((*str) && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10 + (*str - '0');
		str++;
		if (ret * np < (long)-2147483648)
			return (0);
		if (ret * np > (long)2147483647)
			return (-1);
	}
	return ((int)ret * (int)np);
}

void	print_philo_msg(char *action, t_philo *philo)
{
	size_t			print_t;

	pthread_mutex_lock(&philo->info->print_msg);
	print_t = get_time() - philo->finish_eat;
	printf("%zu %d %s\n", print_t, philo->philo_num, action);
	pthread_mutex_unlock(&philo->info->print_msg);	
}

void	check_must_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philos)
	{
		if (philo->info->must_eat > philo->count_eat)
			break;
		if (philo->info->must_eat <= philo->count_eat)
			philo->info->flag_must_eat++;
		if (philo->info->flag_must_eat == philo->info->num_philos)
			philo->info->flag_end = 1;
		i++;
	}
}

void	check_philos_died(t_philo *philo, t_info *info)
{
	int		i;
	size_t	curr_t;

	while (info->flag_end != 1)
	{
		i = 0;
		while (info->flag_end != 1 && i < info->num_philos)
		{
			curr_t = get_time();
			if ((curr_t - philo[i].finish_eat) / 1000 > (size_t)info->time_die)
			{	
				philo[i].info->flag_end = 1;
				print_philo_msg("died", philo);
			}
			i++;
		}
	}
}

void	ft_usleep(size_t stop, t_info *info)
{
	size_t	start;

	start = get_time();
	while (!info->flag_end)
	{
		if (get_time() - start >= stop)
			break ;
		usleep(10);
	}
}
