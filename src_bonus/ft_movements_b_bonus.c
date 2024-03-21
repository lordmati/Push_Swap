/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_b_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:18 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/20 18:15:06 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rb(t_node **head_b)
{
	if (!*head_b)
		return ;
	*head_b = (*head_b)->next;
}

void	rrb(t_node **head_b)
{
	if (!*head_b)
		return ;
	*head_b = (*head_b)->prev;
}

void	rr(t_node **head, t_node **head_b)
{
	ra(head);
	rb(head_b);
}

void	rrr(t_node **head, t_node **head_b)
{
	rra(head);
	rrb(head_b);
}

void	sb(t_node **head)
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
