/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:35:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/27 19:01:43 by dapark           ###   ########.fr       */
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
	//a_print(stack);
	sorting(stack);
	//a_print(stack);
	return (0);
}
