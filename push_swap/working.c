/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:28:56 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/20 18:58:14 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
{
	t_node *tmp;
	
	if(name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
	
}

void	push(t_stack *stack, char name)
{
	t_node *tmp;
	
	if(name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
}

void	rotate(t_stack *stack, char name)
{
	t_node *tmp;
	
	if(name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
}

void	reverse_rotate(t_stack *stack, char name)
{
	t_node *tmp;
	
	if(name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
}