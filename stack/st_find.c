/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:45:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/16 16:20:15 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	st_find(t_stack *stack, int number)
{
	size_t	index;
	t_list	*node;

	index = 0;
	if (stack && stack->count)
	{
		node = stack->first;
		while (node)
		{
			index++;
			if (node->number == number)
				return (index);
			node = node->next;
		}
		index = 0;
	}
	return (index);
}
