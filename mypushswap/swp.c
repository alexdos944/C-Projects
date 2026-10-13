/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:57:29 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 14:37:48 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_sa(t_list *stack, t_bench *bench)
{
	if (!stack || !stack->next)
		return ;
	ft_swap_int(&stack->data, &stack->next->data);
	if (!bench->count_only)
		ft_printf("sa\n");
	bench->sa++;
	bench->total++;
}

void	ft_sb(t_list *stack, t_bench *bench)
{
	if (!stack || !stack->next)
		return ;
	ft_swap_int(&stack->data, &stack->next->data);
	if (!bench->count_only)
		ft_printf("sb\n");
	bench->sb++;
	bench->total++;
}

void	ft_ss(t_list *stack_a, t_list *stack_b, t_bench *bench)
{
	if (stack_a && stack_a->next)
		ft_swap_int(&stack_a->data, &stack_a->next->data);
	if (stack_b && stack_b->next)
		ft_swap_int(&stack_b->data, &stack_b->next->data);
	if (!bench->count_only)
		ft_printf("ss\n");
	bench->ss++;
	bench->total++;
}

void	ft_pa(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_push(stack_b, stack_a);
	if (!bench->count_only)
		ft_printf("pa\n");
	bench->pa++;
	bench->total++;
}

void	ft_pb(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_push(stack_a, stack_b);
	if (!bench->count_only)
		ft_printf("pb\n");
	bench->pb++;
	bench->total++;
}
