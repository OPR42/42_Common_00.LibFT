/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:26:31 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:26:32 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

/*#include <stdio.h>*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	total;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	dst = malloc (total);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((unsigned char *)dst)[i] = '\0';
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	int i;
	char *tab1 = "AbCdEfGhIj";
	char *tab2 = "AbCdEfGhIj";
	int	n = 24;

	printf("%d bytes before ft_calloc :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab1[i]);
		i++;
	}
	printf("\n\n");
	tab1 = ft_calloc (24, sizeof(int));
	printf("Same %d bytes after ft_calloc :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab1[i]);
		i++;
	}
	printf("\n\n");
	free(tab1);
	printf("Same %d bytes after ft_calloc and free :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab1[i]);
		i++;
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("%d bytes before calloc :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab2[i]);
		i++;
	}
	printf("\n\n");
	tab2 = ft_calloc (24, sizeof(int));
	printf("Same %d bytes after calloc :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab2[i]);
		i++;
	}
	printf("\n\n");
	free(tab2);
	printf("Same %d bytes after calloc and free :\n", n);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab2[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
