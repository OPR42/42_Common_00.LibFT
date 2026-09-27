/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:26:42 by orobert           #+#    #+#             */
/*   Updated: 2025/10/27 13:26:43 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	*src;
	char	*dest1;
	char	*dest2;

	src = "Se traîne un petit soleil jaunâtre et minable";
	dest1 = ft_strdup(src);
	dest2 = strdup(src);
	printf("Src       : %s\nft_strdup : %s\nstrdup    : %s\n"
		, src, dest1, dest2);
	free (dest1);
	free (dest2);
}*/
