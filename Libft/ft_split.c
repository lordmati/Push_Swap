/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:02:12 by misaguir          #+#    #+#             */
/*   Updated: 2023/10/14 16:41:25 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (word);
}

static size_t	ft_word_size(char const *s, char c, int m)
{
	int	size;

	size = 0;
	while (s[m] != c && s[m])
	{
		size++;
		m++;
	}
	return (size);
}

static char	**ft_free_all(char **str)
{
	int	t;

	t = 0;
	while (str[t])
	{
		free(str[t]);
		t++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	j;
	int		k;

	j = 0;
	k = 0;
	str = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (str == NULL)
		return (0);
	while (j < ft_word_count(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		str[j] = ft_substr(s, k, ft_word_size(s, c, k));
		if (str[j] == NULL)
			return (ft_free_all(str));
		k = k + ft_word_size(s, c, k);
		j++;
	}
	str[j] = NULL;
	return (str);
}
