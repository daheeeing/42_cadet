/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:52:17 by dapark            #+#    #+#             */
/*   Updated: 2023/03/17 23:30:24 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define FORK 4

typedef struct s_info
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				flag_must_eat;
	int				flag_end;
	size_t			time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_msg;
}	t_info;

typedef struct s_philo
{
	int			right_fork;
	int			left_fork;
	int			philo_num;
	int			count_eat;
	pthread_t	thread;
	size_t		finish_eat;
	t_info		*info;
}	t_philo;

int		init_info(int argc, char **argv, t_info *info);
t_philo	*init_philo(t_info *info);
size_t	get_time();
int		destroy_philos(t_philo	*philo);
int		ft_atoi(char *str);
void	print_philo_msg(char *action, t_philo *philo);
void	check_must_eat(t_philo *philo);
void	check_philos_died(t_philo *philo, t_info *info);
int		philos_born(t_info *info, t_philo *philo);
void	*philos_eat(t_philo *philo);
void	*philos_sleep(t_philo *philo);
void	*philos_think(t_philo *philo);
void	*philos_activities(t_philo *philo);


#endif
