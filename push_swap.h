/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:00:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/05/19 16:52:43 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define FLAG_BENCH    1
# define FLAG_SIMPLE   2
# define FLAG_MEDIUM   4
# define FLAG_COMPLEX  8
# define FLAG_ADAPTIVE 16
# define FLAG_ALGO_MASK 30

# define STRAT_NONE    0
# define STRAT_SIMPLE  1
# define STRAT_MEDIUM  2
# define STRAT_COMPLEX 3

enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
};

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_context
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
	int			total;
	int			flags;
	int			op_count;
	int			op_counts[OP_COUNT];
	int			disorder;
	int			strategy;
}	t_context;

typedef struct s_cost
{
	int			cost_a;
	int			cost_b;
	int			total;
	t_node		*node;
}	t_cost;

void		exec_op(t_context *ctx, int op);

int			ft_strlen_ps(const char *s);

int			parse_single_arg(t_context *ctx, const char *arg);
int			parse_args(t_context *ctx, int argc, char **argv);

int			has_duplicate(t_node *stack, int value);
int			is_sorted(t_node *stack);

t_node		*new_node(int value);
void		append_node(t_node **stack, t_node *node);
void		init_context(t_context *ctx);

int			stack_size(t_node *stack);
t_node		*find_min(t_node *stack);
t_node		*find_max(t_node *stack);
t_node		*last_node(t_node *stack);
int			get_position(t_node *stack, t_node *target);

void		index_stack(t_context *ctx);

void		sa(t_context *ctx);
void		sb(t_context *ctx);
void		ss(t_context *ctx);

void		pa(t_context *ctx);
void		pb(t_context *ctx);

void		ra(t_context *ctx);
void		rb(t_context *ctx);
void		rr(t_context *ctx);

void		rra(t_context *ctx);
void		rrb(t_context *ctx);
void		rrr(t_context *ctx);

void		sort_two(t_context *ctx);
void		sort_three(t_context *ctx);

void		sort_five(t_context *ctx);

void		sort_simple(t_context *ctx);

void		sort_medium(t_context *ctx);

void		sort_complex(t_context *ctx);

void		sort_adaptive(t_context *ctx);

int			*compute_lis(t_context *ctx, int *lis_len);

t_cost		find_cheapest(t_context *ctx);
t_node		*find_target_in_a(t_context *ctx, t_node *b_node);

void		execute_move(t_context *ctx, t_cost *move);
void		final_align(t_context *ctx);

int			calc_disorder(t_context *ctx);

void		print_bench(t_context *ctx);

void		free_stack(t_node **stack);
void		free_context(t_context *ctx);

void		error_exit(t_context *ctx);
void		ft_putnbr_fd(int n, int fd);

#endif
