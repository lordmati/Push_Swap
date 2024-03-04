/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:41 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 17:56:44 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nodo;

	new_lst = NULL;
	if (!lst || !del)
		return (NULL);
	while (lst)
	{
		nodo = ft_lstnew(NULL);
		if (!nodo)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		nodo->content = f(lst->content);
		ft_lstadd_back(&new_lst, nodo);
		lst = lst->next;
	}
	return (new_lst);
}
