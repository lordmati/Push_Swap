/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:22:34 by misaguir          #+#    #+#             */
/*   Updated: 2024/02/27 12:26:39 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_conversions(const char str, va_list element)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += ft_putchar_pf(va_arg(element, int));
	else if (str == 's')
		i += ft_putstr_pf(va_arg(element, char *));
	else if (str == 'p')
		i += ft_point((unsigned long)va_arg(element, void *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr_pf(va_arg(element, int));
	else if (str == 'u')
		i += ft_u(va_arg(element, unsigned int));
	else if (str == 'x')
		i += ft_hexa(va_arg(element, unsigned int));
	else if (str == 'X')
		i += ft_hexaup(va_arg(element, unsigned int));
	else if (str == '%')
		i += write (1, "%%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		pos;
	va_list	element;

	i = 0;
	pos = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start (element, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
			i += ft_conversions(str[++pos], element);
		else
			i += write(1, &str[pos], 1);
		pos++;
	}
	va_end (element);
	return (i);
}
