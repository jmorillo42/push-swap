/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:35:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/22 15:17:19 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*st_node(t_stack *stack, size_t position)
{
	t_list	*node;

	node = NULL;
	if (stack && position && position <= stack->count)
	{
		node = stack->first;
		while (position > 1)
		{
			node = node->next;
			position--;
		}
	}
	return (node);
}
