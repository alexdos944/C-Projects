/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:44:52 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/04 23:37:31 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*noeud;

	result = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		noeud = ft_lstnew(f(lst->content));
		if (!noeud)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, noeud);
		lst = lst->next;
	}
	return (result);
}
/*
void	*dup_upper(void *content)
{
	char *src;
	char *copy;
	int i;

	src = (char *)content;
	copy = malloc(ft_strlen(src) + 1);
	if (!copy)
	return (NULL);
	i = 0;
	while (src[i])
	{
		if (src[i] >= 'a' && src[i] <= 'z')
			copy[i] = src[i] - 32;
		else
			copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	del(void *content)
{
	(void)content;
}

void	print(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *lst;
	t_list *result;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("un"));
	ft_lstadd_back(&lst, ft_lstnew("deux"));
	ft_lstadd_back(&lst, ft_lstnew("trois"));
	result = ft_lstmap(lst, dup_upper, del);
	ft_lstiter(result, print);
	ft_lstclear(&lst, del);
	ft_lstclear(&result, del);
	return (0);
}*/