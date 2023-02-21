/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:28:56 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/21 23:32:10 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
{
	t_node	*stack_ab;
	t_node	*tmp;
	t_node	*top;

	if (name == 'a')
		stack_ab = stack->stack_a;
	if (name == 'b')
		stack_ab = stack->stack_b;
	if ((name == 'a' && stack->size[0] < 1) \
	|| (name == 'b' && stack->size[1] < 1))
		return ;
	tmp = stack_ab->next;
	top = stack_ab;
	top->next = tmp->next;
	tmp->next = top;
	stack_ab = tmp;
	stack_ab->next = top;
	if (name == 'a')
		stack->stack_a = stack_ab;
	if (name == 'b')
		stack->stack_b = stack_ab;
}

void	push(t_stack *stack, char name)
{
	t_node	*top;
	int		top_value;

	if (name == 'a')
	{
		if (stack->size[1] < 1)
			return ;
		top_value = stack->stack_b->value;
		remove_frontnode(stack, 'b');
	}
	if (name == 'b')
	{
		if (stack->size[0] < 1)
			return ;
		top_value = stack->stack_a->value;
		remove_frontnode(stack, 'a');
	}
	top = create_node(top_value);
	add_node(stack, top, name, 1);
}

void	rotate(t_stack *stack, char name)
{
	t_node	*stack_ab;
	t_node	*tmp;
	int		top_val;

	if (name == 'a')
	{
		if (stack->size[0] < 1)
			return ;
		stack_ab = stack->stack_a;
	}
	if (name == 'b')
	{
		if (stack->size[1] < 1)
			return ;
		stack_ab = stack->stack_b;
	}
	top_val = stack_ab->value;
	tmp = create_node(top_val);
	add_node(stack, tmp, name, 0);
	if (name == 'a')
		stack->stack_a = stack_ab;
	if (name == 'b')
		stack->stack_b = stack_ab;
	remove_frontnode(stack, name);
	free(tmp);
}

void	reverse_rotate(t_stack *stack, char name)
{
	t_node	*stack_ab;
	t_node	*tmp;
	int		bottom_val;

	if (name == 'a')
	{
		stack_ab = stack->stack_a;
		if (stack->size[0] < 1)
			return ;
	}
	if (name == 'b')
	{
		stack_ab = stack->stack_b;
		if (stack->size[1] < 1)
			return ;
	}
	while (stack_ab->next != NULL)
		stack_ab = stack_ab->next;
	bottom_val = stack_ab->value;
	tmp = create_node(bottom_val);
	if (name == 'a')
		add_node(stack, tmp, name, 1);
	if (name == 'b')
		add_node(stack, tmp, name, 1);
	remove_backnode(stack, name);
	free(tmp);
}
