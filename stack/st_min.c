/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:58:35 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/22 16:05:20 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_min(t_stack *stack)
{
	t_list	*node;
	int		min_num;

	if (!stack || !stack->count)
		return (0);
	node = stack->first;
	min_num = node->number;
	while (node)
	{
		if (node->number < min_num)
			min_num = node->number;
		node = node->next;
	}
	return (min_num);
}
