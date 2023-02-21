/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:52:59 by dapark            #+#    #+#             */
/*   Updated: 2023/02/21 21:52:09 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int i)
{
	long	np;
	long	ret;

	np = 1;
	ret = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			np *= -1;
		i++;
	}
	while ((str[i] != '\0') && \
			(str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - '0');
			i++;
		if (ret * np < (long)-2147483648)
			print_error(1);
		if (ret * np > (long)2147483647)
			print_error(1);
	}
	return ((int)ret * (int)np);
}

void	chk_duplicate(int *tmp, int	size)
{
	int	i;
	int	j;
	int	chk;

	i = 0;
	while (i < size)
	{
		chk = tmp[i];
		j = i + 1;
		while (j < size)
		{
			if (chk == tmp[j])
				print_error(1);
			j++;
		}
		i++;
	}
	return ;
}