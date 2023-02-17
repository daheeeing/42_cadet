/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:37:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/17 21:20:18 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(int flag)
{
    if (flag == 1)
        write(2, "Error\n", 6);
    exit(1);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] )
	}
}

int check(int argc, char **str)
{
    int i;
	int	*tmp;

    i = 0;
    if (argc < 2)
        error(0);
    while (str[i])
    {
        check_int(str[i]);
		
    }
}