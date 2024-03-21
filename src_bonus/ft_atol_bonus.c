/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:46:20 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/20 18:14:57 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sig;

	sig = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	ft_num_max(num * sig);
	return (num * sig);
}

void	ft_num_max(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_show_error();
}

void	ft_show_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
