/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:39 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:49:34 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mark_lis_nodes(t_context *ctx, int *keep)
{
	t_node	*cur;
	int		i;

	cur = ctx->stack_a;
	i = 0;
	while (cur)
	{
		if (!keep[i])
			cur->index = -(cur->index + 1);
		cur = cur->next;
		i++;
	}
}

static void	push_non_lis(t_context *ctx)
{
	int	size;
	int	median;
	int	i;

	size = ctx->size_a;
	median = ctx->total / 2;
	i = 0;
	while (i < size)
	{
		if (ctx->stack_a->index < 0)
		{
			ctx->stack_a->index = -(ctx->stack_a->index + 1);
			pb(ctx);
			if (ctx->stack_b && ctx->stack_b->index < median)
				rb(ctx);
		}
		else
			ra(ctx);
		i++;
	}
}

static void	cost_loop(t_context *ctx)
{
	t_cost	move;

	while (ctx->size_b > 0)
	{
		move = find_cheapest(ctx);
		execute_move(ctx, &move);
	}
}

void	sort_complex(t_context *ctx)
{
	int		*keep;
	int		lis_len;

	ctx->strategy = STRAT_COMPLEX;
	keep = compute_lis(ctx, &lis_len);
	if (!keep)
		error_exit(ctx);
	mark_lis_nodes(ctx, keep);
	free(keep);
	push_non_lis(ctx);
	cost_loop(ctx);
	final_align(ctx);
}
