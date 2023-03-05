/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:52:59 by dapark            #+#    #+#             */
/*   Updated: 2023/03/06 01:32:00 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int i)
{
	long	np;
	long	ret;

	np = 1;
	ret = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			np *= -1;
		i++;
	}
	while ((str[i] != '\0') && \
			(str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - '0');
			i++;
		if (ret * np < (long)-2147483648)
			print_error(1);
		if (ret * np > (long)2147483647)
			print_error(1);
	}
	return ((int)ret * (int)np);
}

void	chk_duplicate(int *tmp, int size)
{
	int	i;
	int	j;
	int	chk;

	i = 1;
	while (i <= size)
	{
		chk = tmp[i];
		j = i + 1;
		while (j <= size)
		{
			if (chk == tmp[j])
				print_error(1);
			j++;
		}
		i++;
	}
	return ;
}

void	sort_nums(int *nums)
{
	int	i;
	int	j;
	int	temp;
	int	flag;

	i = 1;
	flag = 0;
	while (i <= nums[0] + 1)
	{
		j = 1;
		while (j <= nums[0] - i)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		exit(0);
}

void	cpy_int_arr(int	*store, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->stack_a;
	while (tmp != NULL)
	{
		tmp->value = store[i];
		tmp = tmp->next;
		i++;
	}
	free(store);
}

void	index_stack(int	*nums, t_stack *stack)
{
	int		i;
	t_node	*tmp;
	int		*store;
	int		count;

	i = 1;
	store = malloc(sizeof(int) * stack->size[0]);
	while (i <= nums[0])
	{
		tmp = stack->stack_a;
		count = 0;
		while (tmp != NULL)
		{	
			if (tmp->value == nums[i])
			{
				store[count] = i - 1;
				break ;
			}
			tmp = tmp->next;
			count++;
		}
		i++;
	}
	cpy_int_arr(store, stack);
	free(nums);
}
