/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:50:44 by dapark            #+#    #+#             */
/*   Updated: 2023/01/23 05:20:01 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/proc.h>

int		ft_atoi(const char *str);
int		str_num(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	message(char *str, int pid);
void	msg_to_bit(char target, int pid);
void	bit_to_msg(int signal);

#endif