/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:25:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/22 20:18:31 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static t_list	*create_node(int number);
static void		append_node(t_stack *stack, t_list *node);

int	st_add(t_stack *stack, int number)
{
	t_list	*new_node;

	new_node = create_node(number);
	if (new_node)
		append_node(stack, new_node);
	return (new_node != NULL);
}

static t_list	*create_node(int number)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->number = number;
		new_node->next = NULL;
	}
	return (new_node);
}

static void	append_node(t_stack *stack, t_list *node)
{
	if (stack && node)
	{
		stack->count++;
		if (stack->count == 1)
			stack->first = node;
		else
			stack->last->next = node;
		stack->last = node;
	}
}
