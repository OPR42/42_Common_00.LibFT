/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:25:43 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:25:45 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;
	size_t	n;

	n = 42;
	c = 32;
	while (c <= 127)
	{
		if (ft_memchr(s, c, n) != memchr(s, c, n))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, (char *)ft_memchr(s, c, n), (char *)memchr(s, c, n));
		else
			printf("Value %d %c for n=%zu returned	: %s\n"
				, c, c, n, (char *)ft_memchr(s, c, n));
		c++;
	}
	return (0);
}*/
