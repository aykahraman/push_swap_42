/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:54 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:53:29 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	op_len(int op)
{
	if (op >= OP_RRA)
		return (4);
	return (3);
}

static void	write_op(int op)
{
	const char	*names[OP_COUNT];

	names[OP_SA] = "sa\n";
	names[OP_SB] = "sb\n";
	names[OP_SS] = "ss\n";
	names[OP_PA] = "pa\n";
	names[OP_PB] = "pb\n";
	names[OP_RA] = "ra\n";
	names[OP_RB] = "rb\n";
	names[OP_RR] = "rr\n";
	names[OP_RRA] = "rra\n";
	names[OP_RRB] = "rrb\n";
	names[OP_RRR] = "rrr\n";
	write(1, names[op], op_len(op));
}

void	exec_op(t_context *ctx, int op)
{
	write_op(op);
	ctx->op_count++;
	ctx->op_counts[op]++;
}
