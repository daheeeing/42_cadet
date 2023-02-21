/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:43:52 by daheepark         #+#    #+#             */
/*   Updated: 2023/02/21 22:28:57 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
    int				value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    int      size[2];
    t_node   *stack_a;
    t_node   *stack_b;
}   t_stack;

int			*check(int argc, char **str);
int			*check_duplicate(int **tmp, int *arr_size, int size);
int			*make_int_array(int size, char *str);
int			count_num(char *str);
void		check_int(char *str);
void		print_error(int flag);
void		free_all(int **tmp, int size, int *tmp2);
void		chk_duplicate(int *tmp, int	size);
int			ft_atoi(char *str, int i);
void		make_stack(int	*nums, t_stack *stack);
t_node		*create_node(int value);
void		add_node(t_stack *stack, t_node *new_node, char c, int flag);
t_node		*create_node(int value);
void		remove_frontnode(t_stack *stack, char name);
void		remove_backnode(t_stack *stack, char name);
void		swap(t_stack *stack, char name);
void		push(t_stack *stack, char name);
void		rotate(t_stack *stack, char name);
void		reverse_rotate(t_stack *stack, char name);

void		check_stack_a(t_stack *stack);
void		check_stack_b(t_stack *stack);
#endif
