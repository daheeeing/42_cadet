/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:52:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/21 02:03:47 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_info
{
	int				num_philos;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				must_eat;
	int				count_must_eat;
	int				flag_end;
	long long		time_start;

	pthread_mutex_t	*forks;
	pthread_mutex_t	start_m;
	pthread_mutex_t	print_msg;
	pthread_mutex_t	end_flag;
	pthread_mutex_t	must_eat_count;
}	t_info;

typedef struct s_philo
{
	int			right_fork;
	int			left_fork;
	int			philo_num;
	int			count_eat;
	pthread_t	thread;
	long long	finish_eat;
	t_info		*info;
}	t_philo;

int			init_info(int argc, char **argv, t_info *info);
int			mutex_init_check_error(t_info *info);
t_philo		*init_philo(t_info *info);
long long	get_time(long long flag, t_info *info);
int			destroy_philos(t_philo	*philo);
int			ft_atoi(char *str);
void		print_philo_msg(char *action, t_philo *philo);
void		check_must_eat(t_philo *philo);
int			philos_born(t_info *info, t_philo *philo);
void		philos_eat(t_philo *philo);
void		ft_usleep(long long stop, t_info *info);
void		*philos_activities(t_philo *philo);
void		*only_one_philo(t_philo *philo);

#endif
