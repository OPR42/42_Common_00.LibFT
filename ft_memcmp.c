/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:25:53 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:25:55 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*s1 = "Tout là-bas, aux fins fonds inexplorés et mal famés";
	char	*s2 = "Tout là-bas, aux f1ns fonds inexplorés et mal famés";
	size_t	n = 19;

	printf("S1 : %s\nS2 : %s\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, s1, s2, n, ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	n = 20;
	printf("\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, n, ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	return (0);
}*/
