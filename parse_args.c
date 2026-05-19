/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:25 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/19 16:52:35 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_number(const char **p, long *num)
{
	int	sign;
	int	digit;
	long	limit;

	sign = 1;
	*num = 0;
	if (**p == '-' || **p == '+')
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	if (**p < '0' || **p > '9')
		return (0);
	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long)INT_MIN;
	while (**p >= '0' && **p <= '9')
	{
		digit = **p - '0';
		if (*num > (limit - digit) / 10)
			return (0);
		*num = *num * 10 + digit;
		(*p)++;
	}
	if (**p && **p != ' ' && **p != '\t')
		return (0);
	*num *= sign;
	return (1);
}

static int	add_number(t_context *ctx, const char **p)
{
	long	num;
	t_node	*node;

	if (!read_number(p, &num))
		return (0);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (has_duplicate(ctx->stack_a, (int)num))
		return (0);
	node = new_node((int)num);
	if (!node)
		return (0);
	append_node(&ctx->stack_a, node);
	ctx->size_a++;
	ctx->total++;
	return (1);
}

static int	has_content(const char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			return (1);
		s++;
	}
	return (0);
}

int	parse_single_arg(t_context *ctx, const char *arg)
{
	if (!has_content(arg))
		return (0);
	while (*arg)
	{
		while (*arg == ' ' || *arg == '\t')
			arg++;
		if (*arg == '\0')
			break ;
		if (!add_number(ctx, &arg))
			return (0);
	}
	return (1);
}

int	parse_args(t_context *ctx, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!parse_single_arg(ctx, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
