/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:56:07 by dapark            #+#    #+#             */
/*   Updated: 2022/09/21 23:14:12 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decide_type(char c, va_list *str)
{
	int	length;

	length = 0;
	if (c == 'd' || c == 'i')
		length += put_nbr(va_arg(*str, int));
	else if (c == 'c')
		length += ft_putchar(va_arg(*str, int));
	else if (c == 's')
		length += put_str(va_arg(*str, char *));
	else if (c == 'p')
		length += print_0x(va_arg(*str, unsigned long long));
	else if (c == 'u')
		length += change_num(va_arg(*str, unsigned int));
	else if (c == 'X')
		length += put_hex_upper(va_arg(*str, unsigned int));
	else if (c == 'x')
		length += put_hex_lower(va_arg(*str, unsigned int));
	else if (c == '%')
		length += ft_putchar('%');
	else
		return (-1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			length;
	int			check;

	i = 0;
	length = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check = decide_type(str[i + 1], &ap);
			if (check == -1)
				return (-1);
			length += check;
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
