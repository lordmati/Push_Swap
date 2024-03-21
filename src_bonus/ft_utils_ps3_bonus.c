/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:27:01 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/20 18:15:38 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_moves_stacks(t_node **stack_a, t_node **stack_b, int len)
{
	int		i;
	int		num;
	t_node	*aux_b;
	t_node	*cost_b;

	i = 0;
	num = INT_MAX;
	aux_b = *stack_b;
	cost_b = NULL;
	while (i < len)
	{
		if (ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b) < num)
		{
			num = ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_b);
			cost_b = aux_b;
		}
		aux_b = aux_b->next;
		i++;
	}
	ft_final_moves(stack_a, stack_b, cost_b);
}

void	ft_final_moves(t_node **stack_a, t_node **stack_b, t_node *low_cost_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = low_cost_b->cost_a;
	cost_b = low_cost_b->cost_b;
	if (cost_a < 0 && cost_b < 0)
		ft_move_rotate_rr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_move_rotate_rrr(stack_a, stack_b, &cost_a, &cost_b);
	ft_move_rotate_a(stack_a, stack_b, &cost_a);
	ft_move_rotate_b(stack_a, stack_b, &cost_b);
	move_prints_b(stack_b, stack_a, PA);
}

void	ft_final_step(t_node **stack_a, t_node **stack_b)
{
	int	aux;

	while (ft_list_size(*stack_b) > 0)
	{
		ft_target_find(stack_a, stack_b);
		ft_cost(stack_a, stack_b, ft_list_size(*stack_b));
		ft_moves_stacks(stack_a, stack_b, ft_list_size(*stack_b));
	}
	ft_calc_position(stack_a, ft_list_size(*stack_a));
	aux = ft_find_lower_index(*stack_a);
	ft_final_order(stack_a, stack_b, aux);
}

void	ft_final_order(t_node **stack_a, t_node **stack_b, int aux)
{
	int	i;

	i = 0;
	if (aux <= (ft_list_size(*stack_a) / 2))
	{
		while (i < aux)
		{
			move_prints(stack_a, stack_b, RA);
			i++;
		}
	}
	else
	{
		i = aux;
		while (i < ft_list_size(*stack_a))
		{
			move_prints(stack_a, stack_b, RRA);
			i++;
		}
	}
}
