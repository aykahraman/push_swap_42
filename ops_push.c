/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:12 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:52:18 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!*src)
		return ;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	node->prev = NULL;
	*dst = node;
}

void	pa(t_context *ctx)
{
	push_top(&ctx->stack_a, &ctx->stack_b);
	ctx->size_a++;
	ctx->size_b--;
	exec_op(ctx, OP_PA);
}

void	pb(t_context *ctx)
{
	push_top(&ctx->stack_b, &ctx->stack_a);
	ctx->size_b++;
	ctx->size_a--;
	exec_op(ctx, OP_PB);
}
