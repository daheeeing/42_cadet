/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:31:19 by dapark            #+#    #+#             */
/*   Updated: 2023/02/25 16:10:00 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack *stack, int chunk, int i)
{
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
		{
			if (i < stack->size[0] / 2 && i >= 0)
				reverse_rotate(stack, 'a');
			else
				rotate(stack, 'a');
		}
	}
}

/*void	push_b_to_a(t_stack *stack)
{
	while (stack->size[1] != 0)
	{
		sort_b(b, length);
		push(stack, 'a');
		stack->size[1]	--;
	}
}*/