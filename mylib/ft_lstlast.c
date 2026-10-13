/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:44:40 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/03 17:00:16 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
/*
int main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew("trois"));
	ft_lstadd_front(&lst, ft_lstnew("deux"));
	ft_lstadd_front(&lst, ft_lstnew("un"));
	printf("%s\n", (char *)ft_lstlast(lst)->content);
	return (0);
}*/