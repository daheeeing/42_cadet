/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:56:07 by dapark            #+#    #+#             */
/*   Updated: 2022/09/12 21:30:46 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	decide_type(char *buf)
{
	int	i;

	i = 0;
	while ((buf[i] != '\0'))
	{
		if (buf[i] == 'd')
			ft_putnbr(va_arg(buf, int));
		else if (buf[i] == 'i')


	}
	
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	while (/* condition */)
	{
		if (*str == '%')
			decide_type(ap);

	}
	
}