/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:20 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/12 14:52:02 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_find(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_b;
	int		size_b;
	int		i;
	int		size_a;

	aux_b = *stack_b;
	ft_calc_position(stack_a, ft_list_size(*stack_a));
	ft_calc_position(&aux_b, ft_list_size(aux_b));
	size_b = ft_list_size(aux_b);
	size_a = ft_list_size(*stack_a);
	i = 0;
	while (size_b > i)
	{
		aux_b->target_pos = ft_target_find_norm(stack_a, &aux_b, size_a);
		aux_b = aux_b->next;
		i++;
	}
}

void	ft_push_all_b(t_node **stack_a, t_node **stack_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((*stack_a)->index <= (len / 2))
			move_prints(stack_a, stack_b, PB);
		else
			move_prints(stack_a, stack_b, RA);
		i++;
	}
	while (ft_list_size(*stack_a) > 3)
		move_prints(stack_a, stack_b, PB);
}

int	ft_cost_top(t_node **stack, int pos)
{
	int	num;
	int	count;

	num = ft_list_size(*stack) - pos;
	count = 0;
	if (pos > ft_list_size(*stack) / 2)
		count = (-1) * num;
	else
		count = pos;
	return (count);
}

void	ft_cost(t_node **stack_a, t_node **stack_b, int len)
{
	int		i;
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	i = 0;
	while (i < len)
	{
		aux_b->cost_a = ft_cost_top(&aux_a, aux_b->target_pos);
		aux_b->cost_b = ft_cost_top(&aux_b, aux_b->pos);
		aux_b = aux_b->next;
		i++;
	}
}

int	ft_target_find_norm(t_node **aux_a, t_node **aux_b, int size_a)
{
	int	i;
	int	pos;
	int	ind;

	i = 0;
	ind = INT_MAX;
	while (i < size_a)
	{
		if ((*aux_b)->index < (*aux_a)->index && (*aux_a)->index < ind)
		{
			pos = (*aux_a)->pos;
			ind = (*aux_a)->index;
		}
		i++;
		*aux_a = (*aux_a)->next;
	}
	if (ind == INT_MAX)
		pos = ft_find_lower_index(*aux_a);
	return (pos);
}
