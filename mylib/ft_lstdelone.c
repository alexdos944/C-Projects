/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:24:08 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/04 22:04:56 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	(void)content;
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list *lst;
	t_list *todel;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("un"));
	ft_lstadd_back(&lst, ft_lstnew("deux"));
	ft_lstadd_back(&lst, ft_lstnew("trois"));
	todel = lst->next->next;
	lst->next->next = NULL;
	ft_lstdelone(todel, del);
	printf("%s\n", (char *)lst->content);
	return (0);
}*/