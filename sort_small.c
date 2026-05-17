/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:45:19 by bakumcu           #+#    #+#             */
/*   Updated: 2026/05/17 16:45:21 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_context *ctx)
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
	pb(ctx);
}

void	sort_five(t_context *ctx)
{
	while (ctx->size_a > 3)
		push_min_to_b(ctx);
	sort_three(ctx);
	while (ctx->size_b > 0)
		pa(ctx);
}
