/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:22:11 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:22:13 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <unistd.h>
#include <stdio.h>
#include <ctype.h>*/

int	ft_isalnum(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
		return (0);
	return (8);
}

/*int	main(void)
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isalnum(c) != isalnum(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isalnum(c), isalnum(c));
		else if (ft_isalnum(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isalnum(c));
		c++;
	}
	return (0);
}*/
