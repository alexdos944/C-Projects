/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:24:27 by alexdos           #+#    #+#             */
/*   Updated: 2026/05/03 16:45:23 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew("trois"));
	ft_lstadd_front(&lst, ft_lstnew("deux"));
	ft_lstadd_front(&lst, ft_lstnew("un"));
	printf("taille : %d\n", ft_lstsize(lst)); // 3
}*/