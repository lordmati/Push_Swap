/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:00:07 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 17:12:24 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	int		i;
	int		j;

	con = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (con == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		con[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		con[i] = s2[j];
		i++;
		j++;
	}
	con[i] = '\0';
	return (con);
}
