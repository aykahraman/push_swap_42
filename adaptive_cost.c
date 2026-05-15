/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:35 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 23:55:56 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target_in_a(t_context *ctx, t_node *b_node)
{
	t_node	*current;
	t_node	*target;
	int		best_diff;
	int		diff;

	target = NULL;
	best_diff = INT_MAX;
	current = ctx->stack_a;
	while (current)
	{
		diff = current->index - b_node->index;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_min(ctx->stack_a);
	return (target);
}

static int	calc_cost_b(t_context *ctx, t_node *node)
{
	int	pos;

	pos = get_position(ctx->stack_b, node);
	if (pos <= ctx->size_b / 2)
		return (pos);
	return (-(ctx->size_b - pos));
}

static int	calc_cost_a(t_context *ctx, t_node *target)
{
	int	pos;

	pos = get_position(ctx->stack_a, target);
	if (pos <= ctx->size_a / 2)
		return (pos);
	return (-(ctx->size_a - pos));
}

static int	combined_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = cost_a;
	abs_b = cost_b;
	if (abs_a < 0)
		abs_a = -abs_a;
	if (abs_b < 0)
		abs_b = -abs_b;
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a <= 0 && cost_b <= 0)
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

t_cost	find_cheapest(t_context *ctx)
{
	t_node	*current_b;
	t_cost	best;
	t_cost	candidate;

	best.total = INT_MAX;
	best.node = NULL;
	current_b = ctx->stack_b;
	while (current_b)
	{
		candidate.node = current_b;
		candidate.cost_b = calc_cost_b(ctx, current_b);
		candidate.cost_a = calc_cost_a(ctx,
				find_target_in_a(ctx, current_b));
		candidate.total = combined_cost(candidate.cost_a, candidate.cost_b);
		if (candidate.total < best.total)
			best = candidate;
		current_b = current_b->next;
	}
	return (best);
}
