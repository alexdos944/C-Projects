/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:34:19 by nlaine            #+#    #+#             */
/*   Updated: 2026/06/23 16:00:53 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	is_doublon(t_list *lst, int nb)
{
	while (lst != NULL)
	{
		if (lst->data == nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_valid_format(char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	if (ft_strlen(s) > 18)
		return (0);
	if (!(s[0] == '+' || s[0] == '-') && !(s[0] >= '0' && s[0] <= '9'))
		return (0);
	if ((s[0] == '+' || s[0] == '-') && s[1] == '\0')
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(long n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
}

long	ft_atol(char *s)
{
	int		i;
	long	result;
	int		sign;	

	i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (s[i] == '+')
	{
		sign = 1;
		i++;
	}
	result = ft_atol_convert(s, i);
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
