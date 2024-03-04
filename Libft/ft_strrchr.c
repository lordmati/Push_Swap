/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:02:26 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/15 16:46:08 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	h;

	h = ft_strlen(s);
	while (h >= 0)
	{
		if (s[h] == (char)c)
			return ((char *)&s[h]);
		h--;
	}
	return (0);
}
