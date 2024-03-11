/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:27:01 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/10 18:08:19 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
/* void ft_sum_cost(t_node **stack, int len)
{
	int i;
	t_node *aux;

	i = 0;
	aux = *stack;
	while (len > i)
	{
		aux->cost_total = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
		aux = aux->next;
		i++;	
	}
} */
void	ft_moves_stacks(t_node **stack_a,t_node **stack_b, int len)
{
	int i;
	i = 0;
	t_node *aux_b;
	aux_b = *stack_b;
	int cost_a;
	int cost_b;
	int num;
	num = INT_MAX;
	while (i < len)
	{
		if(ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_a) < num)
		{
			num = ft_abs(aux_b->cost_a) + ft_abs(aux_b->cost_a);
			cost_a = aux_b->cost_a;
			cost_b = aux_b->cost_b;
		}
		aux_b = aux_b->next;
		i++;
	}
	ft_final_moves(stack_a,stack_b,cost_a,cost_b);
}

void ft_final_moves(t_node **stack_a,t_node **stack_b,int cost_a,int cost_b)
{
	if(cost_a < 0 && cost_b < 0)
	{
		while(cost_a < 0 && cost_b < 0)
		{
			move_prints(stack_a,stack_b,RRR);
			cost_a++;
			cost_b++;
		}
	}
	else if(cost_a > 0 && cost_b > 0)
	{
		while(cost_a > 0 && cost_b > 0)
		{
			move_prints_b(stack_a,stack_b,RR);
			cost_a--;
			cost_b--;
		}
	}
	ft_move_rotate_a(stack_a,stack_b,cost_a);
	ft_move_rotate_b(stack_a,stack_b,cost_b);
	move_prints_b(stack_b,stack_a,PA);
}
