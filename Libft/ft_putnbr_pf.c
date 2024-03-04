/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:46:32 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/27 12:26:25 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_calc_num(long n)
{
	size_t	j;

	j = 1;
	if (n < 0)
	{
		n *= -1;
		j++;
	}
	while (n > 9)
	{
		n = (n / 10);
		j++;
	}
	return (j);
}

int	ft_putnbr_pf(int n)
{
	int		len;
	long	ln;

	ln = (long)n;
	len = ft_calc_num(ln);
	if (ln < 0)
	{
		write(1, "-", 1);
		ln *= -1;
	}
	if (ln >= 10)
		ft_putnbr_pf(ln / 10);
	ft_putchar_pf((ln % 10) + '0');
	return (len);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	return (i);
}
