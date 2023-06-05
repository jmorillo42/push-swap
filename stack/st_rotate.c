/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:25:23 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/23 12:02:23 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_rotate(t_stack *stack)
{
	if (stack->count > 1)
	{
		stack->last->next = stack->first;
		stack->last = stack->first;
		stack->first = stack->first->next;
		stack->last->next = NULL;
	}
}
