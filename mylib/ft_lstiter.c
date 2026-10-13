/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:34:55 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/04 22:44:29 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	print(void *content)
{
	printf("%s\n", (char *)content);
}

int main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("un"));
	ft_lstadd_back(&lst, ft_lstnew("deux"));
	ft_lstadd_back(&lst, ft_lstnew("trois"));
	ft_lstiter(lst, print);
	return (0);
}*/