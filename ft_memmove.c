/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:47 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:23:49 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}

/*int	main(void)
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	ft_memmove (s2, s1, 10);
	s2[10] = '\0';
	memmove (s3, s1, 10);
	s3[10] = '\0';
	printf ("Source     : %s\nft_memmove : %s\nmemmove    : %s\n", s1, s2, s3);
}*/
