/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:19:09 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:19:18 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <unistd.h>
#include <stdio.h>
#include <ctype.h>*/

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (0);
	return (1024);
}

/*int	main(void)
{
	int	c;

	c = -256;
	while (c < 256)
	{
		if (ft_isalpha(c) != isalpha(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isalpha(c), isalpha(c));
		else if (ft_isalpha(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isalpha(c));
		c++;
	}
	return (0);
}*/
