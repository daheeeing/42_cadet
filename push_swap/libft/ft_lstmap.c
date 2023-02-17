/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:50:56 by dapark            #+#    #+#             */
/*   Updated: 2022/07/19 19:35:02 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ret_node;

	if (!lst)
		return (0);
	ret = NULL;
	while (lst)
	{
		ret_node = ft_lstnew(f(lst->content));
		if (!ret_node)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, ret_node);
		lst = lst->next;
	}
	ret_node = NULL;
	return (ret);
}
