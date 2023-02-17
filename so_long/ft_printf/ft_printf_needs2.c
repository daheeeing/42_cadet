/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_needs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:14:15 by daheepark         #+#    #+#             */
/*   Updated: 2022/09/22 01:38:21 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_upper(unsigned int num)
{
	unsigned int	num_q;
	unsigned int	num_r;
	int				length;

	length = 0;
	num_q = num / 16;
	num_r = num % 16;
	if (num_q > 0)
		length += put_hex_upper(num_q);
	length += ft_putchar("0123456789ABCDEF"[num_r]);
	return (length);
}

int	put_hex_lower(unsigned int num)
{
	unsigned int	num_q;
	unsigned int	num_r;
	int				length;

	length = 0;
	num_q = num / 16;
	num_r = num % 16;
	if (num_q > 0)
		length += put_hex_lower(num_q);
	length += ft_putchar("0123456789abcdef"[num_r]);
	return (length);
}

int	print_0x(unsigned long long num)
{
	ft_putchar('0');
	ft_putchar('x');
	return (put_voidhex(num) + 2);
}

int	put_voidhex(unsigned long long num)
{
	int	length;

	length = 0;
	if (num / 16 > 0)
		length += put_voidhex(num / 16);
	length += ft_putchar("0123456789abcdef"[num % 16]);
	return (length);
}
