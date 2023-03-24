/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:23:55 by dapark            #+#    #+#             */
/*   Updated: 2023/03/23 22:10:13 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lenlen(char const *str, unsigned int i, size_t len)
{
	size_t	size;
//	size_t	start;

//x	start = i;
	size = ft_strlen(str) - i + 1;
	if (size < len)
		return (size);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		tmp = malloc(1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
		return (tmp);
	}
	length = lenlen(s, start, len);
	tmp = (char *)malloc(sizeof(char) * (length + 1));
	if (!tmp)
		return (NULL);
	while (i < length)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
