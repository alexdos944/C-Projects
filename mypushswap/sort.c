/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:06:17 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 15:45:17 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	sort_three(t_list **stack, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a < b && b < c)
		return ;
	sort_three_helper(stack, bench);
}

void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	pos;

	pos = find_min(*stack_a);
	while (pos--)
		ft_ra(stack_a, bench);
	ft_pb(stack_a, stack_b, bench);
	pos = find_min(*stack_a);
	while (pos--)
		ft_ra(stack_a, bench);
	ft_pb(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	ft_pa(stack_a, stack_b, bench);
	ft_pa(stack_a, stack_b, bench);
}

void	sort_simple(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	min;

	while (*stack_a && (*stack_a)->next)
	{
		if (ft_size(*stack_a) == 3)
		{
			sort_three(stack_a, bench);
			while (*stack_b)
				ft_pa(stack_a, stack_b, bench);
			return ;
		}
		if (ft_size(*stack_a) == 2)
		{
			ft_sa(*stack_a, bench);
			return ;
		}
		min = find_min(*stack_a);
		while (min-- > 0)
			ft_ra(stack_a, bench);
		ft_pb(stack_a, stack_b, bench);
	}
}

void	push_all_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	max;
	int	size;

	while (*stack_b)
	{
		size = ft_size(*stack_b);
		max = find_max(*stack_b);
		if (max <= size / 2)
			while (max-- > 0)
				ft_rb(stack_b, bench);
		else
		{
			max = size - max;
			while (max-- > 0)
				ft_rrb(stack_b, bench);
		}
		ft_pa(stack_a, stack_b, bench);
	}
}

void	sort_medium(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	chunk_size;
	int	chunk;
	int	i;
	int	j;
	int	size;

	chunk_size = ft_sqr(ft_size(*stack_a)) + ft_sqr(ft_size(*stack_a)) / 2;
	chunk = 0;
	ft_rank(*stack_a);
	size = ft_size(*stack_a);
	while (chunk * chunk_size < size)
	{
		i = 0;
		j = ft_size(*stack_a);
		while (i < chunk_size && j--)
		{
			if (is_in_chunk((*stack_a)->rank, chunk, chunk_size))
				push_chunk(stack_a, stack_b, &i, bench);
			else
				ft_ra(stack_a, bench);
		}
		chunk++;
	}
	push_all_a(stack_a, stack_b, bench);
}
