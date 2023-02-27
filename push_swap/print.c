/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:24:21 by dapark            #+#    #+#             */
/*   Updated: 2023/02/27 18:26:41 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	a_print(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_a;
	while(tmp != NULL)
	{
		printf("stack_a == %d\n", tmp->value);
		tmp = tmp->next;
	}
}

void	b_print(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_b;
	while(tmp != NULL)
	{
		printf("stack_b == %d\n", tmp->value);
		tmp = tmp->next;
	}
}