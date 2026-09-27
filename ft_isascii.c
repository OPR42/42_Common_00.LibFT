/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:20:24 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:20:26 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <unistd.h>
#include <stdio.h>
#include <ctype.h>*/

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/*int	main(void)
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isascii(c) != isascii(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
				, c, c, ft_isascii(c), isascii(c));
		else if (ft_isascii(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isascii(c));
		c++;
	}
	return (0);
}*/
