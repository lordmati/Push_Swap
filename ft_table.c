/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:30:35 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/29 16:53:50 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*ft_stack_a(int *tab, int len)
{
	t_node	*head;
	t_node	*aux;
	t_node	*node;
	int		i;

	i = 1;
	head = NULL;
	if (len > 0)
		head = new_node(tab[0]);
	aux = head;
	while (i < len)
	{
		node = new_node(tab[i]);
		aux->next = node;
		node->prev = aux;
		aux = node;
		i++;
	}
	head->prev = node;
	node->next = head;
	return (head);
}