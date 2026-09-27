/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:22:29 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:22:31 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <unistd.h>
#include <stdio.h>
#include <ctype.h>*/

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (16384);
}

/*int	main(void)
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isprint(c) != isprint(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
				, c, c, ft_isprint(c), isprint(c));
		else if (ft_isprint(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isprint(c));
		c++;
	}
	return (0);
}*/
