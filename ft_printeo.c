/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printeo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:05:35 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/06 12:26:09 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printeo(t_node **stack_a,int len)
{
	int i = 0;
	printf("VALOR NODO   VALOR POSICION  VALOR INDICE\n");
	while(i < len)
	{
		printf("%d                 %d                %d\n",(*stack_a)->number,(*stack_a)->pos,(*stack_a)->index);
		*stack_a = (*stack_a)->next;
		i++;
	}
}
void printeo_b(t_node **stack_b,int len)
{
	int i = 0;
	printf("VALOR NODO   VALOR POSICION  VALOR INDICE    VALOR TARGET          VALOR COSTO_A        VALOR COSTO_B\n");
	while(i < len)
	{
		printf("%d                 %d                %d               %d                    %d               %d\n",(*stack_b)->number,(*stack_b)->pos,(*stack_b)->index,(*stack_b)->target_pos,(*stack_b)->cost_a,(*stack_b)->cost_b);
		*stack_b = (*stack_b)->next;
		i++;
	}
}