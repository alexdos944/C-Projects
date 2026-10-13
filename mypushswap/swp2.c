/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:57:34 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 14:38:24 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_ra(t_list **stack, t_bench *bench)
{
	ft_rotate(stack);
	if (!bench->count_only)
		ft_printf("ra\n");
	bench->ra++;
	bench->total++;
}

void	ft_rb(t_list **stack, t_bench *bench)
{
	ft_rotate(stack);
	if (!bench->count_only)
		ft_printf("rb\n");
	bench->rb++;
	bench->total++;
}

void	ft_rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (!bench->count_only)
		ft_printf("rr\n");
	bench->rr++;
	bench->total++;
}

void	ft_rra(t_list **stack, t_bench *bench)
{
	ft_rev_rotate(stack);
	if (!bench->count_only)
		ft_printf("rra\n");
	bench->rra++;
	bench->total++;
}

void	ft_rrb(t_list **stack, t_bench *bench)
{
	ft_rev_rotate(stack);
	if (!bench->count_only)
		ft_printf("rrb\n");
	bench->rrb++;
	bench->total++;
}
