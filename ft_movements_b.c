/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:18 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/11 19:17:10 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void  sb(t_node *head_b) ///// REVISAR
{
    int aux;

    aux = head_b->number;
    head_b->number = head_b->next->number;
    head_b->next->number = aux;
    printf("sb\n");
} */

void rb(t_node **head_b)
{
    *head_b = (*head_b)->next;
}

void rrb(t_node **head_b)
{
    *head_b = (*head_b)->prev;
}

void rr(t_node **head,t_node **head_b)
{
    ra(head);
    rb(head_b);
}
void rrr(t_node **head,t_node **head_b)
{
    rra(head);
    rrb(head_b);
}