/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:48:32 by dapark            #+#    #+#             */
/*   Updated: 2022/09/22 01:36:46 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	decide_type(char c, va_list *str);
int	change_num(unsigned int a);
int	put_nbr(int nb);
int	put_str(char *str);
int	ft_putchar(char a);
int	put_hex_upper(unsigned int num);
int	put_hex_lower(unsigned int num);
int	put_voidhex(unsigned long long num);
int	print_0x(unsigned long long num);

#endif