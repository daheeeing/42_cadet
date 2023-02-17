/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:50:46 by dapark            #+#    #+#             */
/*   Updated: 2023/01/23 05:17:56 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_to_bit(char target, int pid)
{
	int		num_bits;

	num_bits = 0;
	while (num_bits < 8)
	{
		if (target % 2 == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
		else if (target % 2 != 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "kill error", ft_strlen("kill error"));
				exit(1);
			}
		}
		target = target >> 1;
		num_bits++;
		usleep(100);
	}
}

void	message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		msg_to_bit(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3 && str_num(av[1]))
		message(av[2], ft_atoi(av[1]));
	else
		write(1, "ac error\n", 9);
}
