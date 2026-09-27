/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:24:58 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:25:00 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (NULL);
}

/*int	main(void)
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;

	c = 32;
	while (c <= 127)
	{
		if (ft_strchr(s, c) != strchr(s, c))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, ft_strchr(s, c), strchr(s, c));
		else
			printf("Value %d %c returned	: %s\n", c, c, ft_strchr(s, c));
		c++;
	}
	return (0);
}*/
