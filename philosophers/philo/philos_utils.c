/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:07:00 by dapark            #+#    #+#             */
/*   Updated: 2023/03/31 16:46:35 by dapark           ###   ########.fr       */
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

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (-2);
			i++;
		}
		else
			return (-2);
	}
	return (ft_atoi(str));
}

void	*only_one_philo(t_philo *philo)
{
	long long	print_time;

	pthread_mutex_lock(&philo->info->forks_m[philo->left_fork]);
	print_philo_msg("has taken a fork", philo);
	while (philo->info->flag_end != 1)
	{
		print_time = get_time(0, philo);
		if (print_time - philo->finish_eat >= philo->info->time_die)
			philo->info->flag_end = 1;
	}
	printf("%lld %d %s\n", print_time, philo->philo_num, "died");
	return (NULL);
}

void	print_philo_msg(char *action, t_philo *philo)
{
	long long	print_time;
	int			end_flag;

	pthread_mutex_lock(&philo->info->flag_end_m);
	end_flag = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	if (end_flag != 1)
	{
		pthread_mutex_lock(&philo->info->print_msg_m);
		print_time = get_time(0, philo);
		if (print_time - philo->finish_eat > philo->info->time_die)
		{
			pthread_mutex_lock(&philo->info->print_msg_m);
			print_died(philo, print_time);
			return ;
		}
		pthread_mutex_lock(&philo->info->flag_end_m);
		end_flag = philo->info->flag_end;
		pthread_mutex_unlock(&philo->info->flag_end_m);
		if (end_flag != 1)
			printf("%lld %d %s\n", print_time, philo->philo_num, action);
		pthread_mutex_unlock(&philo->info->print_msg_m);
	}
}

void	print_died(t_philo *philo, long long print_time)
{
	int	flag;

	pthread_mutex_lock(&philo->info->flag_end_m);
	flag = philo->info->flag_end;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	if (flag != 1)
		printf("%lld %d %s\n", print_time, philo->philo_num, "died");
	pthread_mutex_lock(&philo->info->flag_end_m);
	philo->info->flag_end = 1;
	pthread_mutex_unlock(&philo->info->flag_end_m);
	pthread_mutex_unlock(&philo->info->print_msg_m);
}
