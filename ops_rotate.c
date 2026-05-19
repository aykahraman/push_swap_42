/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:17 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:52:26 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	tail = last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = tail;
	tail->next = first;
}

void	ra(t_context *ctx)
{
	rotate(&ctx->stack_a);
	exec_op(ctx, OP_RA);
}

void	rb(t_context *ctx)
{
	rotate(&ctx->stack_b);
	exec_op(ctx, OP_RB);
}

void	rr(t_context *ctx)
{
	rotate(&ctx->stack_a);
	rotate(&ctx->stack_b);
	exec_op(ctx, OP_RR);
}
