/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:24:11 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/21 20:17:30 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_gnl(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *es, char *buff)
{
	char	*con;
	int		i;
	int		j;

	if (!es)
	{
		es = malloc(sizeof(char) * 1);
		es[0] = '\0';
	}
	if (!es || !buff)
		return (NULL);
	con = malloc(sizeof(char) * (ft_strlen_gnl(es) + ft_strlen_gnl(buff) + 1));
	if (con == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (es[i] != '\0')
	{
		con[i] = es[i];
		i++;
	}
	while (buff[j] != '\0')
		con[i++] = buff[j++];
	con[i] = '\0';
	return (ft_free_gnl(es), con);
}
