/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:24:40 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:24:41 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <ctype.h>*/

int	ft_tolower(int c)
{
	if (c < 'A' || c > 'Z')
		return (c);
	return (c + 32);
}

/*int	main(void)
{
	int		i;
	char	c;

	i = 32;
	write(1, "ASCII 32-126 : ", 15);
	while (i <= 126)
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "ft_tolower   : ", 15);
	while (i <= 126)
	{
		c = ft_tolower(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "tolower      : ", 15);
	while (i <= 126)
	{
		c = tolower(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/
