/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:01:52 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/25 23:20:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	ac_remove(t_actions *actions, t_dlist *node)
{
	if (!actions || !node)
		return ;
	actions->count--;
	if (actions->first == node)
	{
		actions->first = actions->first->next;
		if (actions->first)
			actions->first->prev = NULL;
	}
	else
		node->prev->next = node->next;
	if (actions->last == node)
	{
		actions->last = actions->last->prev;
		if (actions->last)
			actions->last->next = NULL;
	}
	else
		node->next->prev = node->prev;
	free(node);
}
