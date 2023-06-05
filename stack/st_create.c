/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:15:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/08/15 12:11:24 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*st_create(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack)
	{
		new_stack->count = 0;
		new_stack->first = NULL;
		new_stack->last = NULL;
	}
	return (new_stack);
}
