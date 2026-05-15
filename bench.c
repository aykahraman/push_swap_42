/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:43 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:53:44 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_str(const char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

static void	print_disorder(t_context *ctx)
{
	int	pct;
	int	d1;
	int	d2;

	write_str("Disorder: ", 2);
	pct = ctx->disorder / 10;
	d1 = ctx->disorder % 10;
	d2 = 0;
	ft_putnbr_fd(pct, 2);
	write(2, ".", 1);
	ft_putnbr_fd(d1, 2);
	ft_putnbr_fd(d2, 2);
	write_str("%\n", 2);
}

static void	print_strategy(t_context *ctx)
{
	write_str("Strategy: ", 2);
	if (ctx->strategy == STRAT_SIMPLE)
		write_str("simple (O(n^2))\n", 2);
	else if (ctx->strategy == STRAT_MEDIUM)
		write_str("medium (O(n*sqrt(n)))\n", 2);
	else if (ctx->strategy == STRAT_COMPLEX)
		write_str("complex (O(n log n))\n", 2);
	else
		write_str("none\n", 2);
}

static void	print_op_line(t_context *ctx, int start, int end)
{
	const char	*names[OP_COUNT];
	int			i;

	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	i = start;
	while (i <= end)
	{
		write_str("  ", 2);
		write_str(names[i], 2);
		write_str(": ", 2);
		ft_putnbr_fd(ctx->op_counts[i], 2);
		i++;
	}
	write(2, "\n", 1);
}

void	print_bench(t_context *ctx)
{
	print_disorder(ctx);
	print_strategy(ctx);
	write_str("Total operations: ", 2);
	ft_putnbr_fd(ctx->op_count, 2);
	write(2, "\n", 1);
	print_op_line(ctx, OP_SA, OP_SS);
	print_op_line(ctx, OP_PA, OP_PB);
	print_op_line(ctx, OP_RA, OP_RR);
	print_op_line(ctx, OP_RRA, OP_RRR);
}
