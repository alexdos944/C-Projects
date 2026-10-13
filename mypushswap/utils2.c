/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:05:23 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 16:11:42 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	sort_three_helper(t_list **stack, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a < b && b > c && c > a)
	{
		ft_rra(stack, bench);
		ft_sa(*stack, bench);
	}
	else if (a > b && b < c && c > a)
		ft_sa(*stack, bench);
	else if (a < b && b > c)
		ft_rra(stack, bench);
	else if (a > c && b < c && c < a)
		ft_ra(stack, bench);
	else if (a > b && b > c)
	{
		ft_sa(*stack, bench);
		ft_rra(stack, bench);
	}
}

int	find_min(t_list *stack)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = stack->data;
	pos = 0;
	while (stack->next != NULL)
	{
		i++;
		if (min > stack->next->data)
		{
			min = stack->next->data;
			pos = i;
		}
		stack = stack->next;
	}
	return (pos);
}

int	find_max(t_list *stack)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = stack->rank;
	pos = 0;
	while (stack->next != NULL)
	{
		i++;
		if (max < stack->next->rank)
		{
			max = stack->next->rank;
			pos = i;
		}
		stack = stack->next;
	}
	return (pos);
}

void	push_chunk(t_list **stack_a, t_list **stack_b, int *i, t_bench *bench)
{
	ft_pb(stack_a, stack_b, bench);
	(*i)++;
}

int	is_in_chunk(int rank, int chunk, int chunk_size)
{
	return (rank >= chunk * chunk_size
		&& rank <= (chunk + 1) * chunk_size - 1);
}
