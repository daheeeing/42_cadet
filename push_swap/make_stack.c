/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:10 by dapark            #+#    #+#             */
/*   Updated: 2023/02/23 21:13:17 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_a(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_a;
	while (tmp)
	{
		printf("stack_a = %d\n",tmp->value);
		tmp = tmp->next;
	}
	printf("stack_a size는 %d\n", stack->size[0]);
}

void	check_stack_b(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->stack_b;
	while (tmp)
	{
		printf("stack_b = %d\n",tmp->value);
		tmp = tmp->next;
	}
	printf("stack_b size는 %d\n", stack->size[1]);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		print_error(0);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack *stack, t_node *new_node, char name, int flag)
{
	t_node *ori_node;

	if (name == 'a')
		ori_node = stack->stack_a;
	if (name == 'b')
		ori_node = stack->stack_b;
	if (flag == 1)
	{
		new_node->next = ori_node;
		if (name == 'a')
			stack->stack_a = new_node;
		if (name == 'b')
			stack->stack_b = new_node;
	}
	else
	{
		while (ori_node->next != NULL)
			ori_node = ori_node->next;
		ori_node->next = new_node;
		new_node->next = NULL;
	}
	if (name == 'a')
		stack->size[0]++;
	if (name == 'b')
		stack->size[1]++;
}

void    remove_frontnode(t_stack *stack, char name)
{
    t_node *tmp;

    if (name == 'a')
    {
        tmp = stack->stack_a->next;
        free(stack->stack_a);
        stack->stack_a = tmp;
		stack->size[0]--;
    }
    else
    {
        tmp = stack->stack_b->next;
        free(stack->stack_b);
        stack->stack_b = tmp;
		stack->size[1]--;
    }
	return ;
}

void    remove_backnode(t_stack *stack, char name)
{
    t_node *tmp;
	t_node *prev;

	tmp = NULL;
	if (name == 'a')
		tmp = stack->stack_a;
	if (name == 'b')
		tmp = stack->stack_b;
    while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	prev->next = NULL;
	if (name == 'a')
		stack->size[0]--;
	if (name == 'b')
		stack->size[1]--;
}

void	make_stack_a(int *nums, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 1;
	while (i <= nums[0])
	{
		tmp = create_node(nums[i]);
		if (i == 1)
		{
			stack->stack_a = tmp;
			stack->size[0]++;
		}
		else
			add_node(stack, tmp, 'a', 0);
		i++;
	}
	return ;
}
