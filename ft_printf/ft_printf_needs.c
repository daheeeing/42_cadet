/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_needs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:03:29 by dapark            #+#    #+#             */
/*   Updated: 2022/09/16 14:54:38 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	change_num(unsigned int a)
{
	unsigned int	ar;
	unsigned int	aq;
	char			aa;
	int				length;

	length = 0;
	ar = a % 10;
	aq = a / 10;
	if (aq != 0)
		change_num(aq);
	aa = ar + '0';
	length += ft_putchar(aa);
	return (length);
}

int	put_nbr(int nb)
{
	unsigned int	num1;
	int				length;

	length = 0;
	if (nb >= 0)
	{
		num1 = nb;
		length += change_num(num1);
	}
	else
	{
		num1 = nb * (-1);
		length += ft_putchar('-');
		length += change_num(num1);
	}
	return (length);
}

int	put_str(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}