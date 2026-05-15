/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:42 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:49:30 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static void	push_chunks_to_b(t_context *ctx, int chunk_size)
{
	int	chunk_start;
	int	pushed;
	int	total;

	chunk_start = 0;
	total = ctx->total;
	while (chunk_start < total)
	{
		pushed = 0;
		while (pushed < chunk_size && ctx->size_a > 0)
		{
			if (ctx->stack_a->index >= chunk_start
				&& ctx->stack_a->index < chunk_start + chunk_size)
			{
				pb(ctx);
				if (ctx->stack_b && ctx->stack_b->index
					< chunk_start + chunk_size / 2)
					rb(ctx);
				pushed++;
			}
			else
				ra(ctx);
		}
		chunk_start += chunk_size;
	}
}

static void	bring_max_top_b(t_context *ctx)
{
	t_node	*max;
	int		pos;

	max = find_max(ctx->stack_b);
	pos = get_position(ctx->stack_b, max);
	if (pos <= ctx->size_b / 2)
	{
		while (ctx->stack_b != max)
			rb(ctx);
	}
	else
	{
		while (ctx->stack_b != max)
			rrb(ctx);
	}
}

void	sort_medium(t_context *ctx)
{
	int	chunk_size;

	ctx->strategy = STRAT_MEDIUM;
	chunk_size = ft_sqrt(ctx->total) * 14 / 10;
	if (chunk_size < 1)
		chunk_size = 1;
	push_chunks_to_b(ctx, chunk_size);
	while (ctx->size_b > 0)
	{
		bring_max_top_b(ctx);
		pa(ctx);
	}
}
