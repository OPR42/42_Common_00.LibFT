/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:30 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:23:31 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	ft_memcpy (s2, s1, 10);
	s2[10] = '\0';
	memcpy (s3, s1, 10);
	s3[10] = '\0';
	printf ("Source    : %s\nft_memcpy : %s\nmemcpy    : %s\n", s1, s2, s3);
}*/
