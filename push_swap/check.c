/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:37:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/20 11:55:50 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= 0 && str[i + 1] <= 9))
				printf("1");
				// print_error(1);
			i++;
		}
		else
			// print_error(1);
				printf("2");

	}
}

int	count_num(char *str)
{
	int	i;
	int	cnt;
	int	prev;
	int	flag;

	i = 0;
	cnt = 0;
	prev = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
			flag = 0;
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
		if (prev != flag && flag == 1)
			cnt++;
		prev = flag;
		i++;
	}
	return (cnt);
}
int	*make_int_array(int size, char *str)
{
	int	i;
	int	j;
	int	*ret;

	i = 0;
	j = 0;
	ret = (int *)malloc(sizeof(int) * size);
	while (j < size)
	{
		while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
			i++;
		ret[j] = ft_atoi(str, i);
		while ((str[i] <= '9' && str[i] >= '0') \
				|| str[i] == '+' || str[i] == '-')
			i++;
		j++;
	}
	return (ret);
}

int	*check_duplicate(int **tmp, int *arr_size, int size)
{
	int	i;
	int	j;
	int	*int_arr;
	int	whole_size;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	whole_size = 0;
	while(i < size)
		whole_size += arr_size[i++];
	int_arr = malloc(sizeof(int) * (whole_size + 1));
	i = -1;
	int_arr[0] = whole_size;
	while (++i < size)
	{
		j = -1;
		while (++j < arr_size[i])
			int_arr[k++] = tmp[i][j];
	}
	chk_duplicate(int_arr, whole_size);
	return (int_arr);
}

int *check(int argc, char **str)
{
    int i;
	int	**tmp;
	int	size;
	int	*int_arr;
	int	*size_array;

    i = 1;
    if (argc < 2)
        print_error(1);
	while (str[i])
		check_int(str[i++]);
	i = 1;
	tmp = (int **)malloc(sizeof(int *) * (argc - 1));
    size_array = (int *)malloc(sizeof(int) * (argc - 1));
	while (str[i])
    {
		size = count_num(str[i]);
		size_array[i - 1] = size;
		tmp[i - 1] = make_int_array(size, str[i]);
		i++;
    }
	int_arr = check_duplicate(tmp, size_array, argc - 1);
	free_all(tmp, argc-1, size_array);
	return (int_arr);
}