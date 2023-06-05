/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:25:23 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/23 12:02:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_rrotate(t_stack *stack)
{
	if (stack->count > 1)
	{
		stack->last->next = stack->first;
		stack->first = stack->last;
		while (stack->last->next != stack->first)
			stack->last = stack->last->next;
		stack->last->next = NULL;
	}
}
