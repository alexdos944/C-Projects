/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:06:43 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/01 18:37:06 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
	t_list *lst;
	t_list *node1;
	t_list *node2;

	lst = NULL;
	node1 = ft_lstnew("premier");
	node2 = ft_lstnew("deuxieme");
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	printf("%s\n", (char *)lst->content);        // deuxieme
	printf("%s\n", (char *)lst->next->content);  // premier
	return (0);
}*/