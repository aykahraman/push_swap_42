/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakumcu <bakumcu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:36 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/17 16:42:56 by bakumcu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_context *ctx)
{
	if (ctx->disorder < 200)
		sort_simple(ctx);
	else if (ctx->disorder < 500)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
