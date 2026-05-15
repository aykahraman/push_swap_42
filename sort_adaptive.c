/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:33:36 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:49:41 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_context *ctx)
{
	if (ctx->disorder < 100)
		sort_simple(ctx);
	else if (ctx->disorder < 300)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
