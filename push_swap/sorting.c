/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:31:19 by dapark            #+#    #+#             */
/*   Updated: 2023/02/27 19:24:20 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack *stack, int chunk)
{
	int	i;

	i = 0;
	while (stack->size[0] != 0)
	{
		if (stack->stack_a->value <= i)
		{
			push(stack, 'b');
			i++;
		}
		else if (stack->stack_a->value > i && \
			stack->stack_a->value <= i + chunk)
		{
			push(stack, 'b');
			rotate(stack, 'a');
			i++;
		}
		else if ((stack->stack_a->value) > (i + chunk))
		{
			if (i < stack->size[0] / 2 && i >= 0)
				reverse_rotate(stack, 'a');
			else
				rotate(stack, 'a');
		}
	}
}

void	find_top(t_stack *stack, int top)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->stack_b;
	while (tmp != NULL)
	{
		if (tmp->value == top)
			break ;
		i++;
		tmp = tmp->next;
	}
	while (i > 0)
	{
		if (i > stack->size[1] / 2)
			reverse_rotate(stack, 'b');
		else
			rotate(stack, 'b');
		i--;
	}
}

void	push_b_to_a(t_stack *stack)
{
	while (stack->size[1] != 0)
	{
		find_top(stack, stack->size[1] - 1);
		push(stack, 'a');
	}
}

void	sorting(t_stack *stack)
{
	int	chunk;
	int	size;

	size = stack->size[0];
	if (size == 2)
		swap(stack, 'a');
	else if (size <= 5)
		sorting_min(stack);
	else
	{
		if (size < 500)
			chunk = 15;
		else
			chunk = 30;
		push_all_to_b(stack, chunk);
		push_b_to_a(stack);
	}
	//exit(0);
}
