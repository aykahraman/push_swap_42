/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:00 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:52:09 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_unindexed_min(t_node *stack)
{
	t_node	*current;
	t_node	*min;

	min = NULL;
	current = stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (!min || current->value < min->value)
				min = current;
		}
		current = current->next;
	}
	return (min);
}

void	index_stack(t_context *ctx)
{
	t_node	*node;
	int		rank;

	rank = 0;
	while (rank < ctx->total)
	{
		node = find_unindexed_min(ctx->stack_a);
		if (node)
			node->index = rank;
		rank++;
	}
}
