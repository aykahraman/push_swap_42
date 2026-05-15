/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:32:31 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/15 20:01:06 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

static int	parse_flag(t_context *ctx, const char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		ctx->flags |= FLAG_BENCH;
	else if (ft_strcmp(arg, "--simple") == 0)
		ctx->flags |= FLAG_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		ctx->flags |= FLAG_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		ctx->flags |= FLAG_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		ctx->flags |= FLAG_ADAPTIVE;
	else
		return (0);
	return (1);
}

static void	validate_and_parse(t_context *ctx, int argc, char **argv)
{
	int		selected_algorithms;
	int		arg_index;

	arg_index = 1;
	while (arg_index < argc && argv[arg_index][0] == '-'
		&& argv[arg_index][1] == '-')
	{
		if (!parse_flag(ctx, argv[arg_index]))
			error_exit(ctx);
		arg_index++;
	}
	selected_algorithms = (ctx->flags & FLAG_ALGO_MASK) >> 1;
	if (selected_algorithms
		&& (selected_algorithms & (selected_algorithms - 1)))
		error_exit(ctx);
	if (arg_index >= argc)
	{
		free_context(ctx);
		exit(0);
	}
	if (!parse_args(ctx, argc - arg_index, argv + arg_index))
		error_exit(ctx);
}

static void	dispatch(t_context *ctx)
{
	if (ctx->flags & FLAG_SIMPLE)
		ctx->strategy = STRAT_SIMPLE;
	else if (ctx->flags & FLAG_MEDIUM)
		ctx->strategy = STRAT_MEDIUM;
	else if (ctx->flags & FLAG_COMPLEX)
		ctx->strategy = STRAT_COMPLEX;
	if (ctx->total <= 1 || is_sorted(ctx->stack_a))
		return ;
	if (ctx->total == 2)
		sort_two(ctx);
	else if (ctx->total == 3)
		sort_three(ctx);
	else if (ctx->total <= 5)
		sort_five(ctx);
	else if (ctx->flags & FLAG_SIMPLE)
		sort_simple(ctx);
	else if (ctx->flags & FLAG_MEDIUM)
		sort_medium(ctx);
	else if (ctx->flags & FLAG_COMPLEX)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	init_context(&ctx);
	validate_and_parse(&ctx, argc, argv);
	index_stack(&ctx);
	ctx.disorder = calc_disorder(&ctx);
	dispatch(&ctx);
	if (ctx.flags & FLAG_BENCH)
		print_bench(&ctx);
	free_context(&ctx);
	return (0);
}
