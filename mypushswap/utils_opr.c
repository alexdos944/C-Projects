/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:57:41 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/23 14:38:32 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	if (!bench->count_only)
		ft_printf("rrr\n");
	bench->rrr++;
	bench->total++;
}

void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst;
	t_list	*second;

	tmp = *stack;
	lst = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	second = tmp->next;
	tmp->next = NULL;
	tmp->prev = lst;
	lst->next = tmp;
	second->prev = NULL;
	(*stack) = second;
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	lst = *stack;
	while (lst->next != NULL)
		lst = lst->next;
	before_last = lst->prev;
	before_last->next = NULL;
	lst->next = *stack;
	lst->prev = NULL;
	(*stack)->prev = lst;
	(*stack) = lst;
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (!*stack_from)
		return ;
	tmp = *stack_from;
	*stack_from = tmp->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	tmp->next = *stack_to;
	tmp->prev = NULL;
	if (*stack_to)
		(*stack_to)->prev = tmp;
	*stack_to = tmp;
}
