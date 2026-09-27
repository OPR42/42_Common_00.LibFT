/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:25:25 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:25:27 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
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
		, s1, s2, n, ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	n = 20;
	printf("\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, n, ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	return (0);
}*/
