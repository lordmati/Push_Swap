/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:38:25 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/12 19:37:35 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head)
{
	int	aux;
	int	temp;

	aux = (*head)->number;
	(*head)->number = (*head)->next->number;
	(*head)->next->number = aux;
	temp = (*head)->index;
	(*head)->index = (*head)->next->index;
	(*head)->next->index = temp;
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

void	pa(t_node **head_b, t_node **head)
{
	if (*head_b)
	{
		t_node	*aux;

		aux = *head_b;
		if (*head_b == (*head_b)->next)
			*head_b = NULL;
		else
		{
			(*head_b)->prev->next = (*head_b)->next;
			(*head_b)->next->prev = (*head_b)->prev;
			*head_b = (*head_b)->next;
		}
		if (!(*head))
		{
			aux->next = aux;
			aux->prev = aux;
		}
		else
		{
			aux->next = *head;
			aux->prev = (*head)->prev;
			(*head)->prev->next = aux;
			(*head)->prev = aux;
		}
		*head = aux;
	}
}
