/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:29:07 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:29:15 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_all(char **tab, size_t j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
}

static void	seek_limits(char const *s, char c, size_t *start, size_t *end)
{
	while (s[*start] == c)
		*start = *start + 1;
	*end = *start;
	while (s[*end] && s[*end] != c)
		*end = *end + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	start;
	size_t	end;
	size_t	j;

	if (!s)
		return (NULL);
	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	j = 0;
	start = 0;
	while (s[start])
	{
		seek_limits(s, c, &start, &end);
		if (end > start)
		{
			tab[j++] = ft_substr(s, start, end - start);
			if (!tab[j - 1])
				return (free_all(tab, j - 1), NULL);
		}
		start = end;
	}
	tab[j] = NULL;
	return (tab);
}
