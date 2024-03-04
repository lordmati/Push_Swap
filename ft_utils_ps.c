/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:30:40 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/04 19:44:07 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_highest(t_node *stack)
{
	int		result;
	t_node	*aux;

	aux = stack;
	result = aux->number;
	while (1)
	{
		if (aux->number > result)
			result = aux->number;
		aux = aux->next;
		if (aux == stack)
			break ;
	}
	return (result);
}

void	ft_calc_index(t_node **stack_a, int len, int size, int aux_len)
{
	t_node	*aux;
	t_node	*index_max;
	int		num;

	while (--len > 0)
	{
		aux = *stack_a;
		num = INT_MIN;
		index_max = NULL;
		aux_len = size;
		while (aux_len > 0)
		{
			if (aux->number == INT_MIN && aux->index == -1)
				aux->index = 1;
			if (aux->number > num && aux->index == -1)
			{
				num = aux->number;
				index_max = aux;
			}
			else if (aux_len--)
				aux = aux->next;
		}
		if (index_max != NULL)
			index_max->index = len;
	}
}

void	ft_calc_position(t_node **stack_a, int len)
{
	t_node	*aux;
	t_node	*pos;
	int		i;

	pos = NULL;
	aux = *stack_a;
	i = 0;
	while (len > i)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	ft_list_size(t_node **stack)
{
	int		size;
	t_node	*aux;
	t_node	*initial_node;

	size = 0;
	aux = *stack;
	initial_node = *stack;
	while (aux->next != initial_node)
	{
		size++;
		aux = aux->next;
	}
	return (size + 1);
}

int	ft_find_lower(t_node *stack)
{
	int		result;
	t_node	*aux;

	aux = stack;
	result = aux->number;
	while (1)
	{
		if (aux->number < result)
			result = aux->number;
		aux = aux->next;
		if (aux == stack)
			break ;
	}
	return (result);
}
