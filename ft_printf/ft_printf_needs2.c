/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_needs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:14:15 by daheepark         #+#    #+#             */
/*   Updated: 2022/09/16 14:18:47 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    put_hex_upper(unsigned int num)
{
    unsigned int    num_q;
    unsigned int    num_r;
    int             length;

    length = 0;
    num_q = num / 16;
    num_r = num % 16;
    if (num_q > 16)
        put_hex(num_q);
    else
        length += ft_putchar("0123456789ABCDEF"[num_r]);
    return (length);
}

int    put_hex_lower(unsigned int num)
{
    unsigned int    num_q;
    unsigned int    num_r;
    int             length;

    length = 0;
    num_q = num / 16;
    num_r = num % 16;
    if (num_q > 0)
        put_hex(num_q);
    else
        length += ft_putchar("0123456789abcdef"[num_r]);
    return (length);
}

int put_voidhex(unsigned long long num)
{
    int                 length;
    unsigned long long  num;

    length == 0;
    if (num / 16 > 0)
        put_voidhex(num);
    else
        length += ft_putchar("0");
        length += ft_putchar("x");
        length += ft_putchar("0123456789abcdef"[num % 16]);
    return (length);
}