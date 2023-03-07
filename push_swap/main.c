/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:35:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/03/07 14:12:45 by daheepark        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int flag)
{
	if (flag == 1)
		write(1, "Error\n", 6);
	exit(1);
}

void	free_arr(int **tmp, int size, int *tmp2)
{
	int	i;

	i = 0;
	while (i < size)
		free(tmp[i++]);
	free(tmp);
	free(tmp2);
}

void	print_cmd(char *cmd, char name, int flag)
{
	static char		*prev;
	char			*curr;

	if (flag == 1)
	{
		write(1, prev, ft_strlen(prev));
		write(1, "\n", 1);
		free(prev);
		exit(0);
	}
	curr = ft_strjoin(cmd, name);
	if (!prev)
	{
		prev = malloc(sizeof(char) * 5);
		prev[0] = '\0';
	}
	if (!prev[0])
		ft_strdup(prev, curr);
	else
		cmp_cmd(prev, curr);
	free(curr);
}

void	cmp_cmd(char *prev, char *curr)
{
	if ((!ft_strcmp(prev, "rb\n") && !ft_strcmp(curr, "ra\n")) || \
		(!ft_strcmp(prev, "ra\n") && !ft_strcmp(curr, "rb\n")))
	{
		write(1, "rr\n", 3);
		prev[0] = '\0';
	}
	else if ((!ft_strcmp(prev, "sa\n") && !ft_strcmp(curr, "sb\n")) || \
		(!ft_strcmp(prev, "sb\n") && !ft_strcmp(curr, "sa\n")))
	{
		write(1, "ss\n", 3);
		prev[0] = '\0';
	}
	else if ((!ft_strcmp(prev, "ra\n") && !ft_strcmp(curr, "rra\n")) || \
	(!ft_strcmp(prev, "rra\n") && !ft_strcmp(curr, "ra\n")))
		prev[0] = '\0';
	else
	{
		write(1, prev, ft_strlen(prev));
		write(1, "\n", 1);
		ft_strdup(prev, curr);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		*nums;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size[0] = 0;
	stack->size[1] = 0;
	nums = check(argc, argv);
	make_stack_a(nums, stack);
	sort_nums(nums);
	index_stack(nums, stack);
	sorting(stack);
	print_cmd("\0", '\0', 1);
	return (0);
}
