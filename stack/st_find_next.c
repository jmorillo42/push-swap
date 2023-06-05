/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_find_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:45:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/26 23:47:03 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	st_find_next(t_stack *stack, int number)
{
	t_list	*node;
	size_t	index;
	size_t	num_index;
	int		next_num;

	num_index = 0;
	if (stack && stack->count)
	{
		node = stack->first;
		next_num = 0x7FFFFFFF;
		index = 1;
		while (node)
		{
			if (node->number > number && node->number <= next_num)
			{
				next_num = node->number;
				num_index = index;
			}
			index++;
			node = node->next;
		}
	}
	return (num_index);
}
