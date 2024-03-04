/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:59:07 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 16:45:27 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	m;

	j = 0;
	m = 0;
	while (s[j] && j < start)
		j++;
	while (s[j] && m < len)
	{
		j++;
		m++;
	}
	return (m);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	ls;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	i = 0;
	ls = ft_strlen(s);
	if (start > ls)
		return (ft_strdup(""));
	sub = (char *)malloc(ft_calc(s, start, len) + 1);
	if (sub == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (i >= start && n < len)
		{
			sub[n] = s[i];
			n++;
		}
		i++;
	}
	sub[n] = '\0';
	return (sub);
}
