/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:36:48 by nlaine            #+#    #+#             */
/*   Updated: 2026/06/23 15:54:44 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	free_list(t_list *current)
{
	t_list	*tmp;

	tmp = NULL;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

t_list	*return_free(t_list	*node)
{
	free_list(node);
	return (NULL);
}

t_flag	get_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--simple") == 1)
			return (SIMPLE);
		if (ft_strcmp(av[i], "--medium") == 1)
			return (MEDIUM);
		if (ft_strcmp(av[i], "--complex") == 1)
			return (COMPLEX);
		i++;
	}
	return (ADAPTIVE);
}

int	is_bench(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 1)
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol_convert(char *s, int i)
{
	long	result;

	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > 2147483648)
			return (result * 10);
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result);
}
