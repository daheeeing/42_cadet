/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:10:19 by dapark            #+#    #+#             */
/*   Updated: 2023/03/06 22:21:15 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char c)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!temp)
		return (NULL);
	while (s1[j])
		temp[i++] = s1[j++];
	temp[i++] = c;
	temp[i] = '\0';
	return (temp);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
