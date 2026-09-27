/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:24:14 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:24:15 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	dst_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (src_len + dst_len);
}

/*int	main(void)
{
	char	s1[] = "mais la plupart d'entre elles faisaient";
	char	s2[100] = "Bien des solutions avaient ete suggerees ";
	char	s3[100] = "Bien des solutions avaient ete suggerees ";
	int		len;
	int		len2;
	int		len3;

	len = 70;
	printf ("Source     : %s\nDestination: %s\nSet length : %d\n\n", len);
	printf ("Set length : %d\n\n", len);
	len2 = ft_strlcat (s2, s1, len);
	len3 = strlcat (s3, s1, len);
	printf ("ft_strlcat : %s\n    needed : %d\n", s2, len2);
	printf ("strlcat    : %s\n    needed : %d\n", s3, len3);
	return (0);
}*/
