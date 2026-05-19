/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:15 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:52:22 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = last_node(*stack);
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rra(t_context *ctx)
{
	rev_rotate(&ctx->stack_a);
	exec_op(ctx, OP_RRA);
}

void	rrb(t_context *ctx)
{
	rev_rotate(&ctx->stack_b);
	exec_op(ctx, OP_RRB);
}

void	rrr(t_context *ctx)
{
	rev_rotate(&ctx->stack_a);
	rev_rotate(&ctx->stack_b);
	exec_op(ctx, OP_RRR);
}
