/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:34:19 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/04 17:28:22 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_prints(t_node **stack_a, t_node **stack_b, t_move mov)
{
	if (mov == SA)
	{
		sa(stack_a);
		//ft_printf("sa\n");
	}
	else if (mov == RA)
	{
		ra(stack_a);
		//ft_printf("ra\n");
	}
	else if (mov == RRA)
	{
		rra(stack_a);
		//ft_printf("rra\n");
	}
	else if (mov == PB)
	{
		pb(stack_a,stack_b);
		//ft_printf("pb\n");
	}
}
