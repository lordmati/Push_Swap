/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:45:20 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/27 12:26:18 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_num(unsigned int n)
{
	size_t	j;

	j = 1;
	while (n > 9)
	{
		n = (n / 10);
		j++;
	}
	return (j);
}

int	ft_u(unsigned int n)
{
	int	len;

	len = ft_calc_num(n);
	if (n >= 10)
		ft_putnbr_pf(n / 10);
	ft_putchar_pf((n % 10) + '0');
	return (len);
}
