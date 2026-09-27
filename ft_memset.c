/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:01 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:23:03 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <stdlib.h>*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	int		i;
	char	*tab;

	tab = malloc(24);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	tab = ft_memset(tab, 65, 12);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
	return (0);
}*/
