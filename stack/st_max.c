/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:58:32 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/22 16:04:54 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_max(t_stack *stack)
{
	t_list	*node;
	int		max_num;

	if (!stack || !stack->count)
		return (0);
	node = stack->first;
	max_num = node->number;
	while (node)
	{
		if (node->number > max_num)
			max_num = node->number;
		node = node->next;
	}
	return (max_num);
}
