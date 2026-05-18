/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:21 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/18 14:19:49 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	sa(t_context *ctx)
{
	swap_top(&ctx->stack_a);
	exec_op(ctx, OP_SA);
}

void	sb(t_context *ctx)
{
	swap_top(&ctx->stack_b);
	exec_op(ctx, OP_SB);
}

void	ss(t_context *ctx)
{
	swap_top(&ctx->stack_a);
	swap_top(&ctx->stack_b);
	exec_op(ctx, OP_SS);
}
