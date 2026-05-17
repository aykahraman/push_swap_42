/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:51:47 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/17 16:47:14 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	append_node(t_node **stack, t_node *node)
{
	t_node	*tail;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = node;
	node->prev = tail;
}

static void	zero_op_counts(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		ctx->op_counts[i] = 0;
		i++;
	}
}

void	init_context(t_context *ctx)
{
	ctx->stack_a = NULL;
	ctx->stack_b = NULL;
	ctx->size_a = 0;
	ctx->size_b = 0;
	ctx->total = 0;
	ctx->flags = 0;
	ctx->op_count = 0;
	ctx->disorder = 0;
	ctx->strategy = STRAT_NONE;
	zero_op_counts(ctx);
}
