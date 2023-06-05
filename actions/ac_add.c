/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:25:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/17 10:00:18 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static t_dlist	*create_node(int action);
static void		append_node(t_actions *actions, t_dlist *node);

int	ac_add(t_actions *actions, int action)
{
	t_dlist	*new_node;

	if (!actions)
		return (0);
	new_node = create_node(action);
	if (new_node)
		append_node(actions, new_node);
	return (new_node != NULL);
}

static t_dlist	*create_node(int action)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (new_node)
	{
		new_node->action = action;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return (new_node);
}

static void	append_node(t_actions *actions, t_dlist *node)
{
	if (actions && node)
	{
		actions->count++;
		if (actions->count == 1)
			actions->first = node;
		else
			actions->last->next = node;
		node->prev = actions->last;
		actions->last = node;
	}
}
