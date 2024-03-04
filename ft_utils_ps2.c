/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:07:20 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/04 19:43:50 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_find(t_node **stack_a, t_node **stack_b)
{
	t_node *aux_a;
	t_node *aux_b;
	int		size_b;
	int		i;
	int		j;
	int		ind;
	int		pos;
	int		size_a;

	aux_a = *stack_a;
	aux_b = *stack_b;
	ft_calc_position(&aux_a, ft_list_size(&aux_a));
	ft_calc_position(&aux_b, ft_list_size(&aux_b));
	size_b = ft_list_size(&aux_b);
	size_a = ft_list_size(&aux_a);
	i = 0;
	while(size_b > i)
	{
		j = 0;
		while(size_a > j)
		{
			if(aux_b->pos < aux_a->pos && aux_a->index < ind)
			{
				pos = aux_a->pos;
				ind = aux_a->index;
			}
			j++;
			aux_a = aux_a->next;
		}
		aux_b->target_pos = pos;
		aux_b = aux_b->next;
		i++;
	}
}
void ft_push_all_b(t_node **stack_a,int len)
{
	printf("llega\n");
	int i;
	t_node *stack_b;
	
	i = 0;
	stack_b = NULL;
	while (i < len)
	{
		if ((*stack_a)->index < len / 2)
			pb(stack_a,&stack_b);
		else
			move_prints(stack_a,&stack_b,RA);
		i++;
	}
	while (ft_list_size(stack_a) > 3)
		move_prints(stack_a, &stack_b, PB);
}
