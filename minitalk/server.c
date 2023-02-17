/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:50:38 by dapark            #+#    #+#             */
/*   Updated: 2023/01/23 05:14:19 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_msg(int signal)
{
	static int	target;
	static int	count;
	int			i;
	int			i_num;

	i = 1;
	i_num = 0;
	if (count < 8)
	{
		if (signal == SIGUSR2)
		{
			while (i_num++ < count)
				i *= 2;
			target += i;
		}
		count++;
	}
	if (count == 8)
	{
		ft_putchar(target);
		count = 0;
		target = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "server ID : ", ft_strlen("server ID : "));
	ft_putnbr(pid);
	ft_putchar('\n');
	if (signal(SIGUSR1, bit_to_msg) == SIG_ERR)
	{
		write(1, "kill error", ft_strlen("kill error"));
		exit(1);
	}
	if (signal(SIGUSR2, bit_to_msg) == SIG_ERR)
	{
		write(1, "kill error", ft_strlen("kill error"));
		exit(1);
	}
	while (1)
	{
		pause();
	}
}
