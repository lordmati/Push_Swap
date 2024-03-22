/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:18:21 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/22 18:16:43 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verification(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_repeatnumbers(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] == tab[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_order(t_node *head)
{
	t_node	*aux;
	int		value_head;

	aux = head;
	value_head = aux->number;
	while (aux->next->number != value_head)
	{
		if (aux->number > aux->next->number)
			return (0);
		aux = aux->next;
	}
	return (1);
}
