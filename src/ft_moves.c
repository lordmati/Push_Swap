/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:15 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/25 13:24:51 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_rotate_rrr(t_node **st_a, t_node **st_b, int *c_a, int *c_b)
{
	while (*c_a < 0 && *c_b < 0)
	{
		move_prints(st_a, st_b, RRR);
		(*c_a)++;
		(*c_b)++;
	}
}

void	ft_move_rotate_rr(t_node **st_a, t_node **st_b, int *c_a, int *c_b)
{
	while (*c_a > 0 && *c_b > 0)
	{
		move_prints_b(st_a, st_b, RR);
		(*c_a)--;
		(*c_b)--;
	}
}

void	add_to_head(t_node **head_b, t_node **head)
{
	t_node	*aux;

	aux = *head_b;
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

void	remove_node(t_node **head_b)
{
	t_node	*aux;

	if (*head_b)
	{
		aux = *head_b;
		if (*head_b == (*head_b)->next)
			*head_b = NULL;
		else
		{
			(*head_b)->prev->next = (*head_b)->next;
			(*head_b)->next->prev = (*head_b)->prev;
			*head_b = (*head_b)->next;
		}
	}
}
