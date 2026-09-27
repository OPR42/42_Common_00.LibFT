/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:39:16 by orobert           #+#    #+#             */
/*   Updated: 2025/10/31 11:39:18 by orobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	del_str(void *p)
{
	free(p);
}

static void	print_str(void *p)
{
	printf("[%s] ", (char *)p);
}

static void	*dup_upper(void *p)
{
	char	*s = (char *)p;
	size_t	len = strlen(s);
	char	*out = (char *)malloc(len + 1);
	size_t	i;

	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = (char)toupper((unsigned char)s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}

static t_list	*make_node(const char *s)
{
	char	*dup = strdup(s);
	if (!dup)
		return (NULL);
	return (ft_lstnew(dup));
}

void	test_lst_functions()
{
	t_list *lst = NULL;
	t_list *mapped;

	printf("Testing ft_lstnew, ft_lstaddfront, ft_lstsize, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter and ft_lstmap\n");
	printf("\nSize = %d, content : ", ft_lstsize(lst));
	ft_lstiter(lst, print_str);
	printf("\n");
	ft_lstadd_front(&lst, make_node("War never"));
	printf("\nNew node created using ft_lstnew\nSize = %d, content : ", ft_lstsize(lst));
	ft_lstiter(lst, print_str);
	printf("\n");
	ft_lstadd_front(&lst, make_node("War. "));
	printf("\nNode added at beginning\nSize = %d, content : ", ft_lstsize(lst));
	ft_lstiter(lst, print_str);
	printf("\n");
	ft_lstadd_back(&lst, make_node("changes."));
	printf("\nNode added at end\nSize = %d, content : ", ft_lstsize(lst));
	ft_lstiter(lst, print_str);
	printf("\n");
	printf("\nLast node contains : %s\n", (char *)ft_lstlast(lst)->content);
	printf("ft_lstsize and ft_lstiter have been used previously to display the list.\n");
	mapped = ft_lstmap(lst, dup_upper, del_str);
	printf("\nNew list created, upping all lowercase letters\nSize = %d, content : ", ft_lstsize(mapped));
	ft_lstiter(mapped, print_str);
	printf("\n");
	ft_lstclear(&lst, del_str);
	ft_lstclear(&mapped, del_str);
	printf("Pointers after ft_lstclear, which uses ft_lstdelone : lst = %p, mapped = %p\n\n", (void *)lst, (void *)mapped);
}

void	test_fd_functions(void)
{
	int 	fd;
	int		total;
	int		ret;
	char	file[2000];

	printf("Testing ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd and ft_putchar_fd\n");
	fd = open("test_ft_fd.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return ;
	ft_putstr_fd("War. ", fd);
	ft_putendl_fd("War never changes.", fd);
	ft_putchar_fd('A', fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(42, fd);
	close(fd);
	printf("File 'test_ft_fd.txt' has been created and should contain :\n\n");
	printf("War. War never changes.\nA\n42\n\n");
	total = 0;
	ret = 1;
	fd = open("test_ft_fd.txt", O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return;
	}
	while (ret > 0 && total < 4194304)
	{
		ret = read(fd, file + total, 4194304 - total);
		if (ret > 0)
			total += ret;
	}
	close(fd);
	if (ret < 0 || total == 0)
		return;
	file[total] = '\0';
	printf("File 'test_ft_fd.txt' really contains :\n\n%s\n\n", file);
}

static void	iteri_test(unsigned int i, char *c)
{
	if (i % 2 != 0)
		*c = '*';
}

void	test_striteri(void)
{
	char s[] = "War. War never changes.";

	printf("Testing ft_striteri\n");
	printf("s before : %s\nMapped function inserts stars in even positions\n", s);
	ft_striteri(s, iteri_test);
	printf("s after  : %s\n", s);
}

static char	mapi_test(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	test_strmapi(void)
{
	char *s = "War. War never changes.";
	char *res;

	printf("Testing ft_strmapi\n");
	res = ft_strmapi(s, mapi_test);
	printf("s : %s\nMapped function uppers letters in odd positions\n", s);
	printf("ft_strmapi : %s\n", res);
	free(res);
}

void	test_itoa()
{
	printf("Testing ft_itoa\n");
	printf("ft_itoa(0)           : %s\n", ft_itoa(0));
	printf("ft_itoa(-42)         : %s\n", ft_itoa(-42));
	printf("ft_itoa(2147483647)  : %s\n", ft_itoa(2147483647));
	printf("ft_itoa(-2147483648) : %s\n", ft_itoa(-2147483648));
}

void	test_split()
{
	char *s = "War. War never changes.";
	char c = ' ';
	char **tab;
	int i;

	printf("Testing ft_split\n");
	tab = ft_split(s, c);
	printf("s : \"%s\"\nc : '%c'\n\n", s, c);
	i = 0;
	while (tab[i])
	{
		printf("%d. %s\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	test_strtrim()
{
	char *s1 = "~<= War. War never changes. =>~";
	char *s2 = ". ~<=>";
	char *res;

	printf("Testing ft_strtrim\n");
	res = ft_strtrim(s1, s2);
	printf("S1 : %s\nS2 : %s\nft_strtrim : %s\n", s1, s2, res);
	free(res);
}

void	test_strjoin()
{
	char *res;
	char *s1 = "War. ";
	char *s2 = "War never changes.";

	printf("Testing ft_strjoin\n");
	res = ft_strjoin(s1, s2);
	printf("S1 : %s\nS2 : %s\nft_strjoin : %s\n", s1, s2, res);
	free(res);
}

void	test_substr()
{
	char	*s = "War. War never changes.";
	int		start;
	int		len;

	printf("Testing ft_substr\n");
	start = 9;
	len = 5;
	printf("Src        : %s\nStart, Len : %d, %d\nft_substr  : %s\n\n", s, start, len, ft_substr(s, start, len));
	start = 5;
	len = 18;
	printf("Src        : %s\nStart, Len : %d, %d\nft_substr  : %s\n\n", s, start, len, ft_substr(s, start, len));
}

void	test_strdup()
{
	char	*src;
	char	*dest1;
	char	*dest2;

	printf("Testing ft_strdup\n");
	src = "Se traîne un petit soleil jaunâtre et minable";
	dest1 = ft_strdup(src);
	dest2 = strdup(src);
	printf("Src       : %s\nft_strdup : %s\nstrdup    : %s\n"
		, src, dest1, dest2);
	free (dest1);
	free (dest2);
}

void	test_calloc()
{
	int i;
	char *tab1 = "AbCdEfGhIj";
	char *tab2 = "AbCdEfGhIj";
	int	n = 24;

	printf("Testing ft_calloc\n");
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
}

void	test_atoi()
{
	char	*s;

	printf("Testing ft_atoi\n");
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
}

void	test_strnstr()
{
	char 	*s1 = "Douglas Adams";
	char 	*s2 = "las A";
	size_t	n = 9;
	
	printf("Testing ft_strnstr\n");
	printf("Big        : %s\nLittle     : %s\nn          : %zu\n", s1, s2, n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
	n = 12;
	printf("n          : %zu\n", n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
	n = 8;
	printf("n          : %zu\n", n);
	printf("ft_strnstr : %s\nstrnstr    : %s\n\n", ft_strnstr(s1, s2, n)
		, strnstr(s1, s2, n));
}

void	test_memcmp()
{
	char	*s1 = "Tout là-bas, aux fins fonds inexplorés et mal famés";
	char	*s2 = "Tout là-bas, aux f1ns fonds inexplorés et mal famés";
	size_t	n = 19;

	printf("Testing ft_memcmp\n");
	printf("S1 : %s\nS2 : %s\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, s1, s2, n, ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	n = 20;
	printf("\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, n, ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

void	test_memchr()
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;
	size_t	n;

	printf("Testing ft_memchr\n");
	n = 42;
	c = 32;
	while (c <= 127)
	{
		if (ft_memchr(s, c, n) != memchr(s, c, n))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, (char *)ft_memchr(s, c, n), (char *)memchr(s, c, n));
		else
			printf("Value %d %c for n=%zu returned	: %s\n"
				, c, c, n, (char *)ft_memchr(s, c, n));
		c++;
	}
}

void	test_strncmp()
{
	char	*s1 = "Tout là-bas, aux fins fonds inexplorés et mal famés";
	char	*s2 = "Tout là-bas, aux f1ns fonds inexplorés et mal famés";
	size_t	n = 19;

	printf("Testing ft_strncmp\n");
	printf("S1 : %s\nS2 : %s\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, s1, s2, n, ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	n = 20;
	printf("\nn  : %lu\nft_strncmp	: %d\nstrncmp		: %d\n"
		, n, ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

void	test_strrchr()
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;

	printf("Testing ft_strrchr\n");
	c = 127;
	while (c >= 32)
	{
		if (ft_strrchr(s, c) != strrchr(s, c))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, ft_strrchr(s, c), strrchr(s, c));
		else
			printf("Value %d %c returned	: %s\n", c, c, ft_strrchr(s, c));
		c--;
	}
}

void	test_strchr()
{
	char	*s = "!#%')+-/13579;=?ACEGIKMOQSUWY[]^_`bdfhjlnprtvxz{|}~";
	int		c;

	printf("Testing ft_strchr\n");
	c = 32;
	while (c <= 127)
	{
		if (ft_strchr(s, c) != strchr(s, c))
			printf("Value %d %c DIVERGENCE	: returned %s, should be %s\n"
			, c, c, ft_strchr(s, c), strchr(s, c));
		else
			printf("Value %d %c returned	: %s\n", c, c, ft_strchr(s, c));
		c++;
	}
}

void	test_tolower()
{
	int		i;
	char	c;

	printf("Testing ft_tolower\n");
	i = 32;
	write(1, "ASCII 32-126 : ", 15);
	while (i <= 126)
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "ft_tolower   : ", 15);
	while (i <= 126)
	{
		c = ft_tolower(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "tolower      : ", 15);
	while (i <= 126)
	{
		c = tolower(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	test_toupper()
{
	int		i;
	char	c;

	printf("Testing ft_toupper\n");
	i = 32;
	write(1, "ASCII 32-126 : ", 15);
	while (i <= 126)
	{
		c = i;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "ft_toupper   : ", 15);
	while (i <= 126)
	{
		c = ft_toupper(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	i = 32;
	write(1, "toupper      : ", 15);
	while (i <= 126)
	{
		c = toupper(i);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	test_strlcat(void)
{
	char	s1[] = "mais la plupart d'entre elles faisaient";
	char	s2[100] = "Bien des solutions avaient ete suggerees ";
	char	s3[100] = "Bien des solutions avaient ete suggerees ";
	int		len;
	int		len2;
	int		len3;

	printf("Testing ft_strlcat\n");
	len = 70;
	printf ("Source     : %s\nDestination: %s\n", s1, s2);
	printf ("Set length : %d\n\n", len);
	len2 = ft_strlcat (s2, s1, len);
	len3 = strlcat (s3, s1, len);
	printf ("ft_strlcat : %s\n    needed : %d\n", s2, len2);
	printf ("strlcat    : %s\n    needed : %d\n", s3, len3);
}

void	test_strlcpy()
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	printf("Testing ft_strlcpy\n");
	ft_strlcpy (s2, s1, 11);
	strlcpy (s3, s1, 11);
	printf ("Source     : %s\nft_strlcpy : %s\nstrlcpy    : %s\n", s1, s2, s3);
}

void	test_memmove()
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	printf("Testing ft_memmove\n");
	ft_memmove (s2, s1, 10);
	s2[10] = '\0';
	memmove (s3, s1, 10);
	s3[10] = '\0';
	printf ("Source     : %s\nft_memmove : %s\nmemmove    : %s\n", s1, s2, s3);
}

void	test_memcpy()
{
	char *s1 = "abcdefghij";
	char s2[11];
	char s3[11];

	printf("Testing ft_memcpy\n");
	ft_memcpy (s2, s1, 10);
	s2[10] = '\0';
	memcpy (s3, s1, 10);
	s3[10] = '\0';
	printf ("Source    : %s\nft_memcpy : %s\nmemcpy    : %s\n", s1, s2, s3);
}

void	test_bzero()
{
	int		i;
	char	*tab;

	tab = malloc(24);
	printf("Testing ft_bzero\nThis is a 24-size tab :\n");
	i = 0;
	while (i < 24)
	{
		tab[i] = i + 42;
		printf("%d ", tab[i]);
		i++;
	}
	printf("\nSame 24-size tab after ft_bzero(tab, 12) :\n");
	tab = ft_bzero(tab, 12);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
}

void	test_memset()
{
	int		i;
	char	*tab;

	tab = malloc(24);
	printf("Testing ft_memset\nThis is a 24-size tab :\n");
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\nSame 24-size tab after ft_memset(tab, 65, 12) :\n");
	tab = ft_memset(tab, 65, 12);
	i = 0;
	while (i < 24)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
}

void	test_strlen()
{
	char	*str1 = "abcdef";
	char	*str2 = "0123456789";
	char	*str3;

	printf("Testing ft_strlen\n");
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
	str3 = malloc (255);
	write(1, "Enter your string to measure, send with Ctrl+D : ", 49);
	read(0, str3, 1023);
	write(1, "\n", 1);
	if (ft_strlen(str3) != strlen(str3))
		printf("String %s DIVERGENCE	: returned %lu, should be %lu\n"
				, str3, ft_strlen(str3), strlen(str3));
	else if (ft_strlen(str3) != 0)
		printf("String %s returned	: %lu\n", str3, ft_strlen(str3));
	free (str3);
}

void	test_isprint()
{
	int	c;

	printf("Testing ft_isprint from -255 to 255, displaying only non-zero results\n");
	c = -255;
	while (c < 256)
	{
		if (ft_isprint(c) != isprint(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
				, c, c, ft_isprint(c), isprint(c));
		else if (ft_isprint(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isprint(c));
		c++;
	}
}

void	test_isascii()
{
	int	c;

	printf("Testing ft_isascii from -255 to 255, displaying only non-zero results\n");
	c = -255;
	while (c < 256)
	{
		if (ft_isascii(c) != isascii(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
				, c, c, ft_isascii(c), isascii(c));
		else if (ft_isascii(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isascii(c));
		c++;
	}
}

void	test_isalnum()
{
	int	c;

	printf("Testing ft_isalnum from -255 to 255, displaying only non-zero results\n");
	c = -255;
	while (c < 256)
	{
		if (ft_isalnum(c) != isalnum(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isalnum(c), isalnum(c));
		else if (ft_isalnum(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isalnum(c));
		c++;
	}
}

void	test_isdigit()
{
	int	c;

	printf("Testing ft_isdigit from -255 to 255, displaying only non-zero results\n");
	c = -255;
	while (c < 256)
	{
		if (ft_isdigit(c) != isdigit(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isdigit(c), isdigit(c));
		else if (ft_isdigit(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isdigit(c));
		c++;
	}
}

void	test_isalpha()
{
	int	c;

	printf("Testing ft_isalpha from -255 to 255, displaying only non-zero results\n");
	c = -255;
	while (c < 256)
	{
		if (ft_isalpha(c) != isalpha(c))
			printf("Value %d %c DIVERGENCE	: returned %d, should be %d\n"
			, c, c, ft_isalpha(c), isalpha(c));
		else if (ft_isalpha(c) != 0)
			printf("Value %d %c returned	: %d\n", c, c, ft_isalpha(c));
		c++;
	}
}

int	mainchoice()
{
	int	choice;

	choice = 0;
	printf("\n---===========################### LIBC FUNCTIONS ###################===========---\n");
	printf("01. isalpha      02. isdigit      03. isalnum      04. isascii      05. isprint\n");
	printf("06. strlen       07. memset       08. bzero        09. memcpy       10. memmove\n");
	printf("11. strlcpy      12. strlcat      13. toupper      14. tolower      15. strchr\n");
	printf("16. strrchr      17. strncmp      18. memchr       19. memcmp       20. strnstr\n");
	printf("21. atoi         22. calloc       23. strdup\n");
	printf("\n---===========################ ADDITIONAL FUNCTIONS ################===========---\n");
	printf("31. substr       32. strjoin      33. strtrim      34. split        35. itoa\n");
	printf("36. strmapi      37. striteri     38. fd_functions\n");
	printf("\n---===========################## BONUS  FUNCTIONS ##################===========---\n");
	printf("41. lst_functions\n");
	printf("\nEnter function number to test it. 99 to exit : ");
	scanf("%d", &choice);
	write(1, "\n", 1);

	return (choice);
}

int	main(void)
{
	int	choice;

	printf("\033[H\033[J");
	choice = 0;
	while (1)
	{
		choice = mainchoice();
		printf("\033[H\033[J");
		if (choice == 99)
		{
			printf("Thank you, have a nice day :)\n\n");
			break;
		}
		else if (choice == 1)
			test_isalpha();
		else if (choice == 2)
			test_isdigit();
		else if (choice == 3)
			test_isalnum();
		else if (choice == 4)
			test_isascii();
		else if (choice == 5)
			test_isprint();
		else if (choice == 6)
			test_strlen();
		else if (choice == 7)
			test_memset();
		else if (choice == 8)
			test_bzero();
		else if (choice == 9)
			test_memcpy();
		else if (choice == 10)
			test_memmove();
		else if (choice == 11)
			test_strlcpy();
		else if (choice == 12)
			test_strlcat();
		else if (choice == 13)
			test_toupper();
		else if (choice == 14)
			test_tolower();
		else if (choice == 15)
			test_strchr();
		else if (choice == 16)
			test_strrchr();
		else if (choice == 17)
			test_strncmp();
		else if (choice == 18)
			test_memchr();
		else if (choice == 19)
			test_memcmp();
		else if (choice == 20)
			test_strnstr();
		else if (choice == 21)
			test_atoi();
		else if (choice == 22)
			test_calloc();
		else if (choice == 23)
			test_strdup();
		else if (choice == 31)
			test_substr();
		else if (choice == 32)
			test_strjoin();
		else if (choice == 33)
			test_strtrim();
		else if (choice == 34)
			test_split();
		else if (choice == 35)
			test_itoa();
		else if (choice == 36)
			test_strmapi();
		else if (choice == 37)
			test_striteri();
		else if (choice == 38)
			test_fd_functions();
		else if (choice == 41)
			test_lst_functions();
		else
			choice = 99;
	}
	return (0);
}
