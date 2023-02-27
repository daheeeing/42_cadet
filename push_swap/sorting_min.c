/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:06:48 by dapark            #+#    #+#             */
/*   Updated: 2023/02/27 19:19:09 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_min(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->stack_a;
	if (stack->size[0] == 3)
		sort_three(stack, 0);
	else if (stack->size[0] == 4)
		sort_four(stack, 1);
	else
	{
		while (tmp != NULL)
		{
			if (tmp->value == 0)
				break ;
			i++;
			tmp = tmp->next;
		}
		move_top_min(stack, i);
		push(stack, 'b');
		sort_four(stack, 2);
		push(stack, 'a');
	}
}

void	move_top_min(t_stack *stack, int i)
{
	if (i == 4)
		reverse_rotate(stack, 'a');
	else if (i == 3)
	{
		reverse_rotate(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else
	{
		while (i-- > 0)
			rotate(stack, 'a');
	}
}

void	sort_four(t_stack *stack, int i)
{
	t_node	*tmp;
	int		j;

	j = 0;
	tmp = stack->stack_a;
	while (tmp != NULL)
	{
		if (tmp->value == 0 + i - 1)
			break ;
		j++;
		tmp = tmp->next;
	}
	while (j-- > 0)
		rotate(stack, 'a');
	push(stack, 'b');
	sort_three(stack, i);
	push(stack, 'a');
}

void	sort_three(t_stack *stack, int i)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	if (tmp->value == 0 + i && tmp->next->value == 2 + i)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (tmp->value == 1 + i)
	{
		if (tmp->next->value == 0 + i)
			swap(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	else if (tmp->value == 2 + i)
	{
		if (tmp->next->value == 0 + i)
			rotate(stack, 'a');
		else
		{
			rotate(stack, 'a');
			swap(stack, 'a');
		}
	}
}
