/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:25:14 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:25:15 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

/*int	main(void)
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;

	c = 127;
	while (c >= 32)
	{
		if (ft_strrchr(s, c) != strrchr(s, c))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, ft_strrchr(s, c), strrchr(s, c));
		else
			printf("Value %d %c returned	: %s\n", c, c, ft_strrchr(s, c));
		c--;
	}
	return (0);
}*/
