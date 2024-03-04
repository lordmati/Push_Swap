/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:53:03 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/27 12:26:13 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
		return (ft_putchar_pf(base[n]));
	else
	{
		i += ft_hexa(n / 16);
		i += ft_hexa(n % 16);
	}
	return (i);
}

int	ft_hexaln(unsigned long n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
		return (ft_putchar_pf(base[n]));
	else
	{
		i += ft_hexaln(n / 16);
		i += ft_hexaln(n % 16);
	}
	return (i);
}

int	ft_hexaup(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n < 16)
		return (ft_putchar_pf(base[n]));
	else
	{
		i += ft_hexaup(n / 16);
		i += ft_putchar_pf(base[n % 16]);
	}
	return (i);
}

int	ft_point(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
	{
		write (1, "0x0", 3);
		return (3);
	}
	else
	{
		write (1, "0x", 2);
		i += ft_hexaln(n);
		return (i + 2);
	}
}

int	ft_putchar_pf(int c)
{
	write (1, &c, 1);
	return (1);
}
