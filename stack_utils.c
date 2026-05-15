/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 00:51:08 by akahrama          #+#    #+#             */
/*   Updated: 2026/05/14 00:51:23 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min;
	t_node	*current;

	min = stack;
	current = stack->next;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max;
	t_node	*current;

	max = stack;
	current = stack->next;
	while (current)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	get_position(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
