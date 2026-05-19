/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:47 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:51:46 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_inversions(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	int		count;

	count = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				count++;
			j = j->next;
		}
		i = i->next;
	}
	return (count);
}

int	calc_disorder(t_context *ctx)
{
	long	inversions;
	long	pairs;

	if (ctx->total <= 1)
		return (0);
	inversions = count_inversions(ctx->stack_a);
	pairs = (long)ctx->total * (ctx->total - 1) / 2;
	return ((int)(inversions * 1000 / pairs));
}
