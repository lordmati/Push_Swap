/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:18 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/12 19:24:40 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **head_b)
{
	*head_b = (*head_b)->next;
}

void	rrb(t_node **head_b)
{
	*head_b = (*head_b)->prev;
}

void	rr(t_node **head, t_node **head_b)
{
	ra(head);
	rb(head_b);
}

void	rrr(t_node **head, t_node **head_b)
{
	rra(head);
	rrb(head_b);
}
