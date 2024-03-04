/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:52:58 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/04 17:49:36 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nstr;
	unsigned int	i;
	int				ns;

	i = 0;
	ns = ft_strlen(s);
	nstr = malloc(sizeof(char) * ns + 1);
	if (nstr == NULL)
		return (0);
	while (s[i] != '\0')
	{
		nstr[i] = (*f)(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
