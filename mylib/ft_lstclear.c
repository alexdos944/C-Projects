/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:05:29 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/04 22:48:51 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextsave;

	if (!lst ||!del)
		return ;
	while (*lst)
	{
		nextsave = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = nextsave;
	}
	*lst = NULL;
}
/*
void	del(void *content)
{
	(void)content;
}

int	main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("un"));
	ft_lstadd_back(&lst, ft_lstnew("deux"));
	ft_lstadd_back(&lst, ft_lstnew("trois"));
	printf("avant : %d wagons\n", ft_lstsize(lst));
	ft_lstclear(&lst, del);
	printf("apres : %d wagons\n", ft_lstsize(lst));
	printf("lst est NULL : %d\n", lst == NULL);
return (0);
}*/