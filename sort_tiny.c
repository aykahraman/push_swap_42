/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:52 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:51:56 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_context *ctx)
{
	if (ctx->stack_a->index > ctx->stack_a->next->index)
		sa(ctx);
}

static int	get_max_idx(t_node *stack)
{
	int		max;
	t_node	*current;

	max = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

void	sort_three(t_context *ctx)
{
	int	max;

	max = get_max_idx(ctx->stack_a);
	if (ctx->stack_a->index == max)
		ra(ctx);
	else if (ctx->stack_a->next->index == max)
		rra(ctx);
	if (ctx->stack_a->index > ctx->stack_a->next->index)
		sa(ctx);
}
