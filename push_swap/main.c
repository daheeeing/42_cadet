/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:35:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/21 23:38:02 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int flag)
{
	if (flag == 1)
    	write(1, "Error\n", 6);
    exit(1);
}

void	free_all(int **tmp, int size, int *tmp2)
{
	int	i;

	i = 0;
	if (!tmp)
	{
		while(i < size)
			free(tmp[i++]);
		free(tmp);
	}
	if (!tmp2)
		free(tmp2);
}

int main(int argc, char **argv)
{
	t_stack	*stack;
    int		*nums;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size[0] = 0;
	stack->size[1] = 0;
    nums = check(argc, argv);
	make_stack(nums, stack);
	/*push(stack, 'b');
	push(stack, 'b');
	push(stack, 'b');
	push(stack, 'a');
	rotate(stack, 'a');
	printf("함수를 거치고 나면\n");*/
	check_stack_a(stack);
	check_stack_b(stack);
	//system("leaks push_swap");
	return (0);
}