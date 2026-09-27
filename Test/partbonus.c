#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

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

int	main(void)
{
	t_list *lst = NULL;
	t_list *mapped;

	/* build: front/back mix */
	ft_lstadd_front(&lst, make_node("world"));
	ft_lstadd_front(&lst, make_node("hello"));
	ft_lstadd_back(&lst, make_node("libft"));
	printf("size = %d\n", ft_lstsize(lst));
	printf("last = %s\n", (char *)ft_lstlast(lst)->content);

	/* iterate */
	printf("iter : ");
	ft_lstiter(lst, print_str);
	printf("\n");

	/* map to UPPER */
	mapped = ft_lstmap(lst, dup_upper, del_str);
	printf("map  : ");
	ft_lstiter(mapped, print_str);
	printf("\n");

	/* clear both */
	ft_lstclear(&lst, del_str);
	ft_lstclear(&mapped, del_str);

	/* check cleared */
	printf("after clear: lst=%p, mapped=%p\n", (void *)lst, (void *)mapped);
	return 0;
}
