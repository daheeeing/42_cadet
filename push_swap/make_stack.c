/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:10 by dapark            #+#    #+#             */
/*   Updated: 2023/02/20 18:09:27 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_a(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_a;
	while (tmp)
	{
		printf("stack_a == %d\n",tmp->value);
		tmp = tmp->next;
	}
}

void	check_stack_b(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_b;
	while (tmp)
	{
		printf("stack_b == %d\n",tmp->value);
		tmp = tmp->next;
	}
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_node(t_node *ori_node, t_node *new, int flag)
{
	if (flag == 1)
		new->next = ori_node;
	else
	{
		while(ori_node->next != NULL)
			ori_node = ori_node->next;
		ori_node->next = new;
		new->next = NULL;
	}
	return ;
}

void    remove_frontnode(t_stack *stack, char name)
{
    t_node *tmp;

    if (name == 'a')
    {
        tmp = stack->stack_a->next;
        free(stack->stack_a);
        stack->stack_a = tmp;
    }
    else
    {
        tmp = stack->stack_b->next;
        free(stack->stack_b);
        stack->stack_b = tmp;   
    }
}

void    remove_backnode(t_stack *stack, char name)
{
    t_node *tmp;
	t_node *prev;

	tmp = NULL;
	if (name == 'a')
		tmp = stack->stack_a;
	if(name == 'b')
		tmp = stack->stack_b;
    while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	prev->next = NULL;
}

void	make_stack(int	*nums, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while(i <= nums[0])
	{
		tmp = create_node(nums[i]);
		if (i == 1)
			stack->stack_a = tmp;
		else
			add_node(stack->stack_a, tmp, 0);
		i++;
	}
	remove_backnode(stack, 'a');
	check_stack_a(stack);
	return ;
}
