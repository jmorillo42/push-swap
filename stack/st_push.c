/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:42:15 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/23 12:02:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_list	*pull_node(t_stack *stack);
static void		push_node(t_stack *stack, t_list *node);

void	st_push(t_stack *source, t_stack *target)
{
	t_list	*node;

	if (source->count)
	{
		node = pull_node(source);
		if (node)
			push_node(target, node);
	}
}

static t_list	*pull_node(t_stack *stack)
{
	t_list	*node;

	node = NULL;
	if (stack && stack->count)
	{
		node = stack->first;
		stack->first = stack->first->next;
		node->next = NULL;
		stack->count--;
		if (!stack->count)
			stack->last = NULL;
	}
	return (node);
}

static void	push_node(t_stack *stack, t_list *node)
{
	if (stack && node)
	{
		stack->count++;
		node->next = stack->first;
		stack->first = node;
		if (stack->count == 1)
			stack->last = node;
	}
}
