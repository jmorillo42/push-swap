/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:15:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 08:58:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_destroy(t_stack **stack)
{
	t_stack	*st;

	st = *stack;
	if (!st)
		return ;
	while (st->first)
	{
		st->last = st->first;
		st->first = st->first->next;
		free(st->last);
	}
	st->count = 0;
	st->first = NULL;
	st->last = NULL;
	free(*stack);
	*stack = NULL;
}
