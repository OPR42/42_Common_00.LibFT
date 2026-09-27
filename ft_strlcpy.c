/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:24:02 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:24:03 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (i < size -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*int	main(void)
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	ft_strlcpy (s2, s1, 11);
	strlcpy (s3, s1, 11);
	printf ("Source     : %s\nft_strlcpy : %s\nstrlcpy    : %s\n", s1, s2, s3);
}*/
