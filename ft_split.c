/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:54:07 by yel-mako          #+#    #+#             */
/*   Updated: 2024/11/10 18:10:39 by yel-mako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word)
		ft_strlcpy(word, s, len + 1);
	return (word);
}

static char	**free_split(char **split, int i)
{
	while (i-- > 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = malloc_word(s, c);
			if (!split[i])
				return (free_split(split, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
