/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:10:09 by dapark            #+#    #+#             */
/*   Updated: 2022/07/14 15:37:12 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss11;
	unsigned char	*ss22;

	ss11 = (unsigned char *)s1;
	ss22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*ss11 != *ss22)
			return (*ss11 - *ss22);
		ss11++;
		ss22++;
		i++;
	}
	return (0);
}
