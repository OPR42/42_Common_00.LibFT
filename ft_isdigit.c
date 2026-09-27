/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:21:18 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:21:20 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <unistd.h>
#include <stdio.h>
#include <ctype.h>*/

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (2048);
}

/*int	main(void)
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isdigit(c) != isdigit(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isdigit(c), isdigit(c));
		else if (ft_isdigit(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isdigit(c));
		c++;
	}
	return (0);
}*/
