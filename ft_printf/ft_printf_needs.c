/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_needs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:03:29 by dapark            #+#    #+#             */
/*   Updated: 2022/09/12 21:04:11 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	change_num(unsigned int a)
{
	unsigned int	ar;
	unsigned int	aq;
	char			aa;

	ar = a % 10;
	aq = a / 10;
	if (aq != 0)
		change_num(aq);
	aa = ar + '0';
	ft_putchar(aa);
}

void	ft_putnbr(int nb)
{
	unsigned int	num1;

	if (nb >= 0)
		change_num(nb);
	else
	{
		num1 = nb * (-1);
		ft_putchar('-');
		change_num(num1);
	}
}