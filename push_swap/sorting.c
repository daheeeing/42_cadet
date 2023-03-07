/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daheepark <daheepark@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:31:19 by dapark            #+#    #+#             */
/*   Updated: 2023/03/07 14:31:37 by daheepark        ###   ########.fr       */
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
			rotate(stack, 'b');
			i++;
		}
		else if ((stack->stack_a->value) > (i + chunk))
			find_top(stack, i + chunk, 0, 'a');
	}
}

void	find_top(t_stack *stack, int top, int flag, char name)
{
	t_node	*tmp;
	int		i;

	i = 0;	
	if(name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
	while (tmp != NULL)
	{
		if ((tmp->value == top && flag == 1) || \
			(tmp->value <= top && flag == 0))
		{
			move_top(stack, name, i);
			return ;
		}
		i++;
		tmp = tmp->next;
	}
}

void	move_top(t_stack *stack, char name, int i)
{
	int	size;

	if(name == 'a')
		size = stack->size[0];
	if(name == 'b')
		size = stack->size[1];
	if (i > size / 2)
	{
		i = size - i;
		while (i-- > 0)
			reverse_rotate(stack, name);
	}
	else
	{
		while (i-- > 0)
			rotate(stack, name);
	}
}

void	push_b_to_a(t_stack *stack)
{
	while (stack->size[1] != 0)
	{
		find_top(stack, stack->size[1] - 1, 1, 'b');
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
}
