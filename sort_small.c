/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:49 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:49:19 by akahrama         ###   ########.fr       */
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
