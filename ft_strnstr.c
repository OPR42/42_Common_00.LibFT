/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:26:08 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:26:09 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j])
			j++;
		if (i + j > len)
			return (NULL);
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char 	*s1 = "Douglas Adams";
	char 	*s2 = "las A";
	size_t	n = 9;
	
	printf("Big        : %s\nLittle     : %s\nn          : %zu\n", s1, s2, n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
	n = 12;
	printf("n          : %zu\n", n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
	n = 8;
	printf("n          : %zu\n", n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
	return (0);
}*/
