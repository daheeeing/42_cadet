/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:35:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/27 17:32:40 by dapark           ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(stack->stack_a);
	tmp = stack->stack_b;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(stack->stack_b);
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
	check_stack_a(stack);
	printf("나는 바보다\n");
	sort_nums(nums);
	index_stack(nums, stack);
	sorting(stack);
	check_stack_a(stack);
	return (0);
}
