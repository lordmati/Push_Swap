/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:38:25 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/28 16:40:28 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	int	aux;

	aux = (*head)->number;
	(*head)->number = (*head)->next->number;
	(*head)->next->number = aux;
}

void	ra(t_node **head)
{
	*head = (*head)->next;
}

void	rra(t_node **head)
{
	*head = (*head)->prev;
}

void	pb(t_node **head, t_node **head_b)
{
	t_node	*aux;

	aux = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	if (!(*head_b))
	{
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		(*head)->next = *head_b;
		(*head)->prev = (*head_b)->prev;
		(*head_b)->prev->next = *head;
		(*head_b)->prev = *head;
	}
	*head_b = *head;
	*head = aux;
}

/* void ss(t_node **head,t_node **head_b)/////// REVISAR
{
    sa(*head);
    sb(*head_b);
} */