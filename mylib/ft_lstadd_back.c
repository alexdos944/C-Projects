/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:09:48 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/03 18:00:18 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
	return ;
}
/*
int main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("un"));
	ft_lstadd_back(&lst, ft_lstnew("deux"));
	ft_lstadd_back(&lst, ft_lstnew("trois"));
	printf("%s\n", (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);
	printf("%s\n", (char *)lst->next->next->content);
	return (0);
}*/