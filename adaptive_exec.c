/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:38 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:53:54 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_both_pos(t_context *ctx, t_cost *m)
{
	while (m->cost_a > 0 && m->cost_b > 0)
	{
		rr(ctx);
		m->cost_a--;
		m->cost_b--;
	}
	while (m->cost_a > 0)
	{
		ra(ctx);
		m->cost_a--;
	}
	while (m->cost_b > 0)
	{
		rb(ctx);
		m->cost_b--;
	}
}

static void	exec_both_neg(t_context *ctx, t_cost *m)
{
	while (m->cost_a < 0 && m->cost_b < 0)
	{
		rrr(ctx);
		m->cost_a++;
		m->cost_b++;
	}
	while (m->cost_a < 0)
	{
		rra(ctx);
		m->cost_a++;
	}
	while (m->cost_b < 0)
	{
		rrb(ctx);
		m->cost_b++;
	}
}

static void	exec_mixed(t_context *ctx, t_cost *m)
{
	while (m->cost_a > 0)
	{
		ra(ctx);
		m->cost_a--;
	}
	while (m->cost_a < 0)
	{
		rra(ctx);
		m->cost_a++;
	}
	while (m->cost_b > 0)
	{
		rb(ctx);
		m->cost_b--;
	}
	while (m->cost_b < 0)
	{
		rrb(ctx);
		m->cost_b++;
	}
}

void	execute_move(t_context *ctx, t_cost *move)
{
	if (move->cost_a >= 0 && move->cost_b >= 0)
		exec_both_pos(ctx, move);
	else if (move->cost_a <= 0 && move->cost_b <= 0)
		exec_both_neg(ctx, move);
	else
		exec_mixed(ctx, move);
	pa(ctx);
}

void	final_align(t_context *ctx)
{
	t_node	*min;
	int		pos;

	min = find_min(ctx->stack_a);
	pos = get_position(ctx->stack_a, min);
	if (pos <= ctx->size_a / 2)
	{
		while (ctx->stack_a != min)
			ra(ctx);
	}
	else
	{
		while (ctx->stack_a != min)
			rra(ctx);
	}
}
