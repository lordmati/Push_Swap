/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:56:01 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 17:11:34 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_num(long n)
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

char	*ft_itoa(int n)
{
	char	*m;
	size_t	i;
	long	ln;

	ln = (long)n;
	i = ft_calc_num(ln);
	m = malloc(sizeof(char) * (i + 1));
	if (m == NULL)
		return (0);
	m[i] = '\0';
	if (ln < 0)
	{
		m[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		m[0] = '0';
	while (ln > 9)
	{
		m[--i] = (ln % 10) + '0';
		ln /= 10;
	}
	if (ln > 0)
		m[--i] = ln + '0';
	return (m);
}
