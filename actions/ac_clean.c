/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:29:27 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/30 14:01:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	remove_reverse(t_actions *ac);
static void	join_opposite(t_actions *ac);
static void	redux_comb(t_actions *ac);

void	ac_clean(t_actions *ac)
{
	size_t	count;

	count = 0;
	while (ac->count != count)
	{
		count = ac->count;
		remove_reverse(ac);
		join_opposite(ac);
		redux_comb(ac);
	}
}

static void	remove_reverse(t_actions *ac)
{
	t_dlist	*node;
	t_dlist	*node_rev;
	t_dlist	*aux;

	node = ac->first;
	while (node && node->next)
	{
		node_rev = ac_find_reverse(node);
		if (node_rev)
		{
			ac_remove(ac, node_rev);
			aux = node;
			node = node->next;
			ac_remove(ac, aux);
		}
		else
			node = node->next;
	}
}

static void	join_opposite(t_actions *ac)
{
	t_dlist	*node;
	t_dlist	*node_op;

	node = ac->first;
	while (node && node->next)
	{
		node_op = ac_find_opposite(node);
		if (node_op)
		{
			if (node->action == SWAP_A || node->action == SWAP_B)
				node->action = SWAP_ALL;
			else if (node->action == ROTATE_A || node->action == ROTATE_B)
				node->action = ROTATE_ALL;
			else if (node->action == RROTATE_A || node->action == RROTATE_B)
				node->action = RROTATE_ALL;
			ac_remove(ac, node_op);
		}
		node = node->next;
	}
}

static t_dlist	*find_reverse_after_push(t_dlist *node, int action)
{
	while (node && ((action == ROTATE_A && node->action == ROTATE_B
				&& node->action == RROTATE_B && node->action == SWAP_B)
			|| (action == ROTATE_B && node->action == ROTATE_A
				&& node->action == RROTATE_A && node->action == SWAP_A)))
			node = node->next;
	if (node && ((action == ROTATE_A && node->action == PUSH_B)
			|| (action == ROTATE_B && node->action == PUSH_A)))
	{
		while (node && ((action == ROTATE_A && node->action == ROTATE_A
					&& node->action == RROTATE_A && node->action == SWAP_A)
				|| (action == ROTATE_B && node->action == ROTATE_B
					&& node->action == RROTATE_B && node->action == SWAP_B)))
			node = node->next;
		if (node && node->action == ac_reverse(action))
			return (node);
	}
	return (NULL);
}

static void	redux_comb(t_actions *ac)
{
	t_dlist	*node;
	t_dlist	*node2;

	node = ac->first;
	while (node && node->next)
	{
		if (node->action == ROTATE_A || node->action == ROTATE_B)
		{
			node2 = find_reverse_after_push(node->next, node->action);
			if (node2)
			{
				ac_remove(ac, node2);
				if (node->action == ROTATE_A)
					node->action = SWAP_A;
				else
					node->action = SWAP_B;
			}
		}
		node = node->next;
	}
}
