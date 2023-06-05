/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:16:05 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/22 15:53:18 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_is_sorted(t_stack *stack)
{
	t_list	*node;
	int		prev_number;

	if (!stack)
		return (0);
	else if (stack->count < 2)
		return (1);
	prev_number = 0;
	node = stack->first;
	while (node)
	{
		if (node->number < prev_number)
			return (0);
		prev_number = node->number;
		node = node->next;
	}
	return (1);
}
