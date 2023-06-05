/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:19:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 09:26:46 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_number(t_stack *stack, size_t position)
{
	t_list	*node;
	int		number;

	number = 0;
	if (stack && position && position <= stack->count)
	{
		node = stack->first;
		while (position > 1)
		{
			node = node->next;
			position--;
		}
		number = node->number;
	}
	return (number);
}
