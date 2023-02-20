/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:35:11 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/20 17:52:55 by dapark           ###   ########.fr       */
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
	//stack = NULL;
    nums = check(argc, argv);
	make_stack(nums, stack);
	return (0);
}