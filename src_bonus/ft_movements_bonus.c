/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:38:25 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/20 18:15:11 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **head)
{
	int	aux;
	int	temp;

	if (ft_list_size(*head) < 1)
		return ;
	aux = (*head)->number;
	(*head)->number = (*head)->next->number;
	(*head)->next->number = aux;
	temp = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = temp;
}

void	ra(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->next;
}

void	rra(t_node **head)
{
	if (!*head)
		return ;
	*head = (*head)->prev;
}

void	pb(t_node **head, t_node **head_b)
{
	t_node	*aux;

	if (*head)
	{
		aux = *head;
		remove_node(head);
		add_to_head(&aux, head_b);
	}
}

void	pa(t_node **head_b, t_node **head)
{
	t_node	*aux;

	if (*head_b)
	{
		aux = *head_b;
		remove_node(head_b);
		add_to_head(&aux, head);
	}
}
