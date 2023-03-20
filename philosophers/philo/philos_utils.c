/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:07:00 by dapark            #+#    #+#             */
/*   Updated: 2023/03/21 02:10:51 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*only_one_philo(t_philo *philo)
{
	long long	print_t;

	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	while (philo->info->flag_end != 1)
	{
		print_t = get_time(0, philo->info);
		if (print_t - philo->finish_eat >= philo->info->time_die)
			philo->info->flag_end = 1;
	}
	printf("%lld %d %s\n", print_t, philo->philo_num, "died");
	return (NULL);
}

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
	long long	print_t;
	int			flag_end;

	pthread_mutex_lock(&philo->info->end_flag);
	flag_end = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->end_flag);
	if (flag_end != 1)
	{	
		print_t = get_time(0, philo->info);
		if (print_t - philo->finish_eat >= philo->info->time_die)
		{
			pthread_mutex_lock(&philo->info->end_flag);
			philo->info->flag_end = 1;
			pthread_mutex_unlock(&philo->info->end_flag);
			pthread_mutex_lock(&philo->info->print_msg);
			printf("%lld %d %s\n", print_t, philo->philo_num, "died");
			pthread_mutex_unlock(&philo->info->print_msg);
			return ;
		}
		pthread_mutex_lock(&philo->info->print_msg);
		printf("%lld %d %s\n", print_t, philo->philo_num, action);
		pthread_mutex_unlock(&philo->info->print_msg);
	}
}

void	check_must_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philos)
	{
		if (philo->info->must_eat > philo->count_eat)
			break ;
		if (philo->info->must_eat <= philo->count_eat)
		{
			pthread_mutex_lock(&philo->info->must_eat_count);
			philo->info->count_must_eat++;
			pthread_mutex_unlock(&philo->info->must_eat_count);
		}
		if (philo->info->count_must_eat == philo->info->num_philos)
		{
			pthread_mutex_lock(&philo->info->end_flag);
			philo->info->flag_end = 1;
			pthread_mutex_unlock(&philo->info->end_flag);
		}
		i++;
	}
}

void	ft_usleep(long long stop, t_info *info)
{
	long long	start;
	int			flag_end;

	pthread_mutex_lock(&info->end_flag);
	flag_end = info->flag_end;
	pthread_mutex_unlock(&info->end_flag);
	start = get_time(0, info);
	while (!flag_end)
	{
		pthread_mutex_lock(&info->end_flag);
		flag_end = info->flag_end;
		pthread_mutex_unlock(&info->end_flag);
		if (get_time(0, info) - start >= stop)
			break ;
		usleep(10);
	}
}
