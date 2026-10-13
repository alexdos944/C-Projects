/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:57:47 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/24 17:58:25 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_rank(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		i;

	current = stack;
	while (current)
	{
		i = 0;
		compare = stack;
		while (compare)
		{
			if (compare->data < current->data)
				i++;
			compare = compare->next;
		}
		current->rank = i;
		current = current->next;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_sqr(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	if (i - 1 > 0)
		return (i - 1);
	return (1);
}
