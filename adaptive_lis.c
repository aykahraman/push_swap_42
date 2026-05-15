/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:40 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 23:55:56 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_node *stack, int size)
{
	int		*indices;
	int		position;
	t_node	*current;

	indices = malloc(sizeof(int) * size);
	if (!indices)
		return (NULL);
	current = stack;
	position = 0;
	while (current && position < size)
	{
		indices[position] = current->index;
		current = current->next;
		position++;
	}
	return (indices);
}

static int	binary_search(int *tails, int tails_len, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = tails_len - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (tails[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

static int	compute_lis_len(int *indices, int size, int *parent, int *tail_indices)
{
	int	*tails;
	int	tails_len;
	int	index;
	int	insert_pos;

	tails = malloc(sizeof(int) * size);
	if (!tails)
		return (0);
	tails_len = 0;
	index = -1;
	while (++index < size)
	{
		insert_pos = binary_search(tails, tails_len, indices[index]);
		tails[insert_pos] = indices[index];
		tail_indices[insert_pos] = index;
		if (insert_pos > 0)
			parent[index] = tail_indices[insert_pos - 1];
		else
			parent[index] = -1;
		if (insert_pos == tails_len)
			tails_len++;
	}
	free(tails);
	return (tails_len);
}

static void	build_keep(int *parent, int *tail_indices, int lis_len, int *keep)
{
	int	trace_index;
	int	remaining;

	trace_index = tail_indices[lis_len - 1];
	remaining = lis_len - 1;
	while (remaining >= 0)
	{
		keep[trace_index] = 1;
		trace_index = parent[trace_index];
		remaining--;
	}
}

int	*compute_lis(t_context *ctx, int *lis_len)
{
	int	*indices;
	int	*keep;
	int	*work_buffer;
	int	index;

	indices = stack_to_array(ctx->stack_a, ctx->size_a);
	if (!indices)
		return (NULL);
	work_buffer = malloc(sizeof(int) * ctx->size_a * 3);
	keep = malloc(sizeof(int) * ctx->size_a);
	if (!work_buffer || !keep)
		return (free(indices), free(work_buffer), free(keep), NULL);
	index = -1;
	while (++index < ctx->size_a)
		keep[index] = 0;
	index = -1;
	while (++index < ctx->size_a)
		work_buffer[index] = -1;
	*lis_len = compute_lis_len(indices, ctx->size_a,
			work_buffer, work_buffer + ctx->size_a);
	if (*lis_len > 0)
		build_keep(work_buffer, work_buffer + ctx->size_a, *lis_len, keep);
	free(indices);
	free(work_buffer);
	return (keep);
}
