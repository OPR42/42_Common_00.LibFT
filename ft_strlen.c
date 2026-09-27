/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:22:46 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:22:48 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <string.h>*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*int	main(void)
{
	char *str1 = "abcdef";
	char *str2 = "0123456789";

	if (ft_strlen(str1) != strlen(str1))
		printf("String %s DIVERGENCE	: returned %lu, should be %lu\n"
				, str1, ft_strlen(str1), strlen(str1));
	else if (ft_strlen(str1) != 0)
		printf("String %s returned	: %lu\n", str1, ft_strlen(str1));
	if (ft_strlen(str2) != strlen(str2))
		printf("String %s DIVERGENCE	: returned %lu, should be %lu\n"
				, str2, ft_strlen(str2), strlen(str2));
	else if (ft_strlen(str2) != 0)
		printf("String %s returned	: %lu\n", str2, ft_strlen(str2));
	return (0);
}*/
