/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:12:04 by nlaine            #+#    #+#             */
/*   Updated: 2026/06/23 14:36:40 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_verif(t_list *start, char *s)
{
	if (is_valid_format(s) == 0)
		return (0);
	if (is_overflow(ft_atol(s)) == 0)
		return (0);
	if (is_doublon(start, (int)ft_atol(s)) == 0)
		return (0);
	return (1);
}

t_list	*create_node(char *s, t_list *last)
{
	t_list	*current;

	current = malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	current->data = (int)ft_atol(s);
	current->next = NULL;
	current->prev = last;
	if (last != NULL)
		last->next = current;
	return (current);
}

int	is_flag(char *s)
{
	if (ft_strcmp(s, "--simple") == 1 || ft_strcmp(s, "--medium") == 1
		|| ft_strcmp(s, "--complex") == 1 || ft_strcmp(s, "--adaptive") == 1
		|| ft_strcmp(s, "--bench") == 1
		|| ft_strcmp(s, "--count-only") == 1)
		return (1);
	else
		return (0);
}

int	verif_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac && is_flag(av[i]) == 1)
		i++;
	return (i);
}

t_list	*convert(int ac, char **av)
{
	int		i;
	t_list	*start;
	t_list	*current;
	t_list	*last;

	i = verif_flag(ac, av);
	start = NULL;
	last = NULL;
	while (av[i])
	{
		if (check_verif(start, av[i]) == 0)
			return (return_free(start));
		current = create_node(av[i], last);
		if (current == NULL)
			return (return_free(start));
		if (start == NULL)
			start = current;
		last = current;
		i++;
	}
	return (start);
}
