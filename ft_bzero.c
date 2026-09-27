/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:13 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:23:15 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*#include <stdio.h>
#include <stdlib.h>*/

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
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
		tab[i] = i + 42;
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	tab = ft_bzero(tab, 12);
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
