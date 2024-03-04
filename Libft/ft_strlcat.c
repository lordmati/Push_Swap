/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:35:30 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/15 16:48:23 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	lensrc;
	size_t	lendst;
	size_t	res;
	size_t	i;

	s = (char *)src;
	lensrc = ft_strlen(s);
	lendst = ft_strlen(dst);
	res = 0;
	i = 0;
	if (dstsize > lendst)
		res = lensrc + lendst;
	else
		res = lensrc + dstsize;
	while (s[i] && (lendst + 1) < dstsize)
	{
		dst[lendst] = s[i];
		lendst++;
		i++;
	}
	dst[lendst] = '\0';
	return (res);
}
