/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:30:35 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/20 18:15:26 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_move_rotate_a(t_node **stack_a, t_node **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			move_prints(stack_a, stack_b, RA);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			move_prints(stack_a, stack_b, RRA);
			(*cost)++;
		}
	}
}

void	ft_move_rotate_b(t_node **stack_a, t_node **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			move_prints_b(stack_a, stack_b, RB);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			move_prints_b(stack_a, stack_b, RRB);
			(*cost)++;
		}
	}
}

void	free_stack(t_node **head)
{
	t_node	*aux;
	t_node	*temp;
	int		size;

	aux = *head;
	size = ft_list_size(*head);
	while (size > 0)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
		size--;
	}
	head = NULL;
}
