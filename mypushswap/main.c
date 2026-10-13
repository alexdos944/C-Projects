/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:03:52 by nlaine            #+#    #+#             */
/*   Updated: 2026/06/24 18:37:12 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	init_bench(t_bench *bench, int ac, char **av)
{
	bench->bench_mode = is_bench(ac, av);
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->count_only = is_count_only(ac, av);
}

void	run_algo(t_list **stack_a, t_list **stack_b,
	t_flag flag, t_bench *bench)
{
	if (flag == SIMPLE)
		sort_simple(stack_a, stack_b, bench);
	else if (flag == MEDIUM)
		sort_medium(stack_a, stack_b, bench);
	else if (flag == COMPLEX)
		sort_complex(stack_a, stack_b, bench);
	else
		sort_adaptive(stack_a, stack_b, bench);
}

char	*flag_to_str(t_flag flag)
{
	if (flag == SIMPLE)
		return ("Simple / O(n^2)");
	if (flag == MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	if (flag == COMPLEX)
		return ("Complex / O(n log n)");
	return ("Adaptive / O(n log n)");
}

int	is_count_only(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--count-only") == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_flag	flag;
	t_bench	bench;
	float	disorder;

	init_bench(&bench, ac, av);
	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = convert(ac, av);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2), 1);
	flag = get_flag(ac, av);
	disorder = compute_disorder(stack_a);
	if (is_sorted(stack_a))
		return (handle_bench(&bench, disorder, flag),
			free_list(stack_a), 0);
	run_algo(&stack_a, &stack_b, flag, &bench);
	handle_bench(&bench, disorder, flag);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
