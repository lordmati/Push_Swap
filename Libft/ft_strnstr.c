/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:36:44 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 16:44:45 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_nd;
	char	*hs;
	char	*nd;

	hs = (char *)haystack;
	nd = (char *)needle;
	size_nd = ft_strlen(nd);
	i = 0;
	if (size_nd == 0 || haystack == needle)
	{
		return (hs);
	}
	while (i < len && hs[i] != '\0')
	{
		j = 0;
		while (nd[j] == hs[i + j] && hs[i + j] != '\0' && i + j < len
			&& nd[j] != '\0')
			j++;
		if (size_nd == j)
			return (hs + i);
		i++;
	}
	return (0);
}
