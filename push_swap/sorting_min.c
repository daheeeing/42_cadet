/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:06:48 by dapark            #+#    #+#             */
/*   Updated: 2023/02/27 17:30:51 by dapark           ###   ########.fr       */
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
		sort_three(stack);
	else if (stack->size[0] == 4)
		sort_four(stack);
	else
	{
		while (tmp != NULL)
		{
			if (tmp->value == 0)
				break ;
			i++;
			tmp = tmp->next;
		}
		while (i-- > 0)
			rotate(stack, 'a');
		push(stack, 'b');
		sort_four(stack);
	}
}

void	sort_four(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->stack_a;
	while (tmp != NULL)
	{
		if (tmp->value == 0)
			break ;
		i++;
		tmp = tmp->next;
	}
	while (i-- > 0)
		rotate(stack, 'a');
	push(stack, 'b');
	sort_three(stack);
}

void	sort_three(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a;
	if (tmp->value == 0 && tmp->next->value == 2)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (tmp->value == 1)
	{
		if (tmp->next->value == 0)
			swap(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	else
	{
		if (tmp->next->value == 0)
			rotate(stack, 'a');
		else
		{
			rotate(stack, 'a');
			swap(stack, 'a');
		}
	}
}
