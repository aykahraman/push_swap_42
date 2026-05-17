/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:45:14 by bakumcu           #+#    #+#             */
/*   Updated: 2026/05/17 16:46:27 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_min_top(t_context *ctx)
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

void	sort_simple(t_context *ctx)
{
	ctx->strategy = STRAT_SIMPLE;
	while (ctx->size_a > 3)
	{
		bring_min_top(ctx);
		pb(ctx);
	}
	sort_three(ctx);
	while (ctx->size_b > 0)
		pa(ctx);
}
