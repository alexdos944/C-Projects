/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexdos <alexdos@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:39:14 by alexdos           #+#    #+#             */
/*   Updated: 2026/06/24 18:35:32 by alexdos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H

# define LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	ss;
	int	rr;
	int	rrr;
	int	total;
	int	bench_mode;
	int	count_only;
}	t_bench;

typedef enum e_flag
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_flag;

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int		is_count_only(int ac, char **av);
void	sort_three(t_list **stack, t_bench *bench);
void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_simple(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	push_all_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_medium(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	process_bit(t_list **stack_a, t_list **stack_b, int bit,
			t_bench *bench);
void	sort_complex(t_list **stack_a, t_list **stack_b, t_bench *bench);
float	compute_disorder(t_list *stack);
void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	ft_swap_int(int *a, int *b);
void	ft_rotate(t_list **stack);
void	ft_rev_rotate(t_list **stack);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_sa(t_list *stack, t_bench *bench);
void	ft_sb(t_list *stack, t_bench *bench);
void	ft_ss(t_list *stack_a, t_list *stack_b, t_bench *bench);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	ft_pb(t_list **stack_b, t_list **stack_a, t_bench *bench);
void	ft_ra(t_list **stack, t_bench *bench);
void	ft_rb(t_list **stack, t_bench *bench);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	ft_rra(t_list **stack, t_bench *bench);
void	ft_rrb(t_list **stack, t_bench *bench);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_bench *bench);
int		is_sorted(t_list *stack);
int		ft_size(t_list *stack);
void	ft_rank(t_list *stack);
int		ft_sqr(int n);
void	sort_three_helper(t_list **stack, t_bench *bench);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
void	push_chunk(t_list **stack_a, t_list **stack_b, int *i, t_bench *bench);
int		check_verif(t_list *start, char *s);
t_list	*create_node(char *s, t_list *last);
int		is_flag(char *s);
int		verif_flag(int ac, char **av);
t_list	*convert(int ac, char **av);
void	free_list(t_list *current);
t_list	*return_free(t_list	*node);
t_flag	get_flag(int ac, char **av);
int		is_bench(int ac, char **av);
long	ft_atol_convert(char *s, int i);
int		is_doublon(t_list *lst, int nb);
int		is_valid_format(char *s);
int		is_overflow(long n);
long	ft_atol(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int		is_in_chunk(int rank, int chunk, int chunk_size);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	handle_bench(t_bench *bench, float disorder, t_flag flag);
void	print_bench_ops(t_bench *bench);
void	print_bench(t_bench *bench, float disorder, char *strategy);
void	init_bench(t_bench *bench, int ac, char **av);
char	*flag_to_str(t_flag flag);
void	run_algo(t_list **stack_a, t_list **stack_b,
			t_flag flag, t_bench *bench);

#endif