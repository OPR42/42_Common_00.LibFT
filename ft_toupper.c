/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:24:29 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:24:30 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <ctype.h>*/

int	ft_toupper(int c)
{
	if (c < 'a' || c > 'z')
		return (c);
	return (c - 32);
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
	write(1, "ft_toupper   : ", 15);
	while (i <= 126)
	{
		c = ft_toupper(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "toupper      : ", 15);
	while (i <= 126)
	{
		c = toupper(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}*/
