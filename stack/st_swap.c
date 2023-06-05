/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:43:33 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/23 12:02:16 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_swap(t_stack *stack)
{
	int	num_aux;

	if (stack->count > 1)
	{
		num_aux = stack->first->number;
		stack->first->number = stack->first->next->number;
		stack->first->next->number = num_aux;
	}
}
