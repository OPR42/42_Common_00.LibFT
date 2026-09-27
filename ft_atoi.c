/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:26:18 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:26:20 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_atoi(const char *nptr)
{
	size_t			i;
	unsigned int	n;
	int				sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if ('0' > nptr[i] || nptr[i] > '9')
			break ;
		n = (10 * n) + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

/*int	main(void)
{
	char	*s;

	s = "0";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "000042";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "-42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "   -42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "2147483648";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "-2147483648";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "2147483649";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = "-a1b2c3d4";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = " \t   --1337\t 42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = " \t   -1337\t 42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = " \t   +1337\t 42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	s = " \t   ++1337\t 42";
	printf("nptr : '%s'\nft_atoi : %d, atoi : %d\n\n", s, ft_atoi(s), atoi(s));
	return (0);
}*/
