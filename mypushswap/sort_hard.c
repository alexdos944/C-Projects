/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:51:52 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 16:08:12 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	process_bit(t_list **stack_a, t_list **stack_b, int bit, t_bench *bench)
{
	int	i;

	i = ft_size(*stack_a);
	while (i--)
	{
		if (((*stack_a)->rank >> bit) & 1)
			ft_ra(stack_a, bench);
		else
			ft_pb(stack_a, stack_b, bench);
	}
}

void	sort_complex(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	bit;
	int	max_bits;
	int	size;

	bit = 0;
	max_bits = 0;
	size = ft_size(*stack_a);
	ft_rank(*stack_a);
	while ((1 << max_bits) <= size)
	{
		max_bits++;
	}
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit, bench);
		while (*stack_b)
			ft_pa(stack_a, stack_b, bench);
		bit++;
	}
}

float	compute_disorder(t_list *stack)
{
	float	pairs;
	float	mistakes;
	t_list	*current;
	t_list	*compare;

	pairs = 0;
	mistakes = 0;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			pairs = pairs + 1;
			if (current->data > compare->data)
				mistakes = mistakes + 1;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / pairs);
}

void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	float	disorder;

	if (ft_size(*stack_a) == 2)
		return (ft_sa(*stack_a, bench));
	if (ft_size(*stack_a) <= 3)
		return (sort_three(stack_a, bench));
	else if (ft_size(*stack_a) <= 5)
		return (sort_five(stack_a, stack_b, bench));
	disorder = compute_disorder(*stack_a);
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b, bench);
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b, bench);
	else
		sort_complex(stack_a, stack_b, bench);
}
