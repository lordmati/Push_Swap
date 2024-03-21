/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:23:13 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/21 20:17:37 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_file_read(char *estatic, int fd)
{
	int		bytes_read;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (ft_free_gnl(estatic), NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(estatic, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free_gnl(buff);
			ft_free_gnl(estatic);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		if (bytes_read > 0)
			estatic = ft_strjoin_gnl(estatic, buff);
	}
	ft_free_gnl(buff);
	return (estatic);
}

char	*ft_get_line(char *estatic)
{
	int		i;
	char	*line;

	i = 0;
	if (!estatic[i])
		return (NULL);
	while (estatic[i] && estatic[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + ft_strchr_gnl(estatic, '\n') + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (estatic[i] && estatic[i] != '\n')
	{
		line[i] = estatic[i];
		i++;
	}
	if (estatic[i] == '\n')
	{
		line[i] = estatic[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_estatic(char *estatic)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (estatic[i] && estatic[i] != '\n')
		i++;
	if (ft_strlen_gnl(estatic) - i <= 0)
	{
		ft_free_gnl(estatic);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen_gnl(estatic) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (estatic[i])
		str[j++] = estatic[i++];
	str[j] = '\0';
	ft_free_gnl(estatic);
	estatic = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*estatic;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_gnl(estatic));
	estatic = ft_file_read(estatic, fd);
	if (!estatic)
		return (ft_free_gnl(estatic), NULL);
	line = ft_get_line(estatic);
	estatic = ft_new_estatic(estatic);
	return (line);
}
