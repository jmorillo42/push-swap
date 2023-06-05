/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_find_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:14:02 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 19:44:14 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

t_dlist	*ac_find_reverse(t_dlist *node)
{
	int	action;

	action = node->action;
	node = node->next;
	if ((action == PUSH_A || action == PUSH_B || action == SWAP_ALL
			|| action == ROTATE_ALL || action == RROTATE_ALL)
		&& node && node->action == ac_reverse(action))
		return (node);
	else if (action == SWAP_A || action == ROTATE_A || action == RROTATE_A)
	{
		while (node && (node->action == ROTATE_B || node->action == RROTATE_B
				|| node->action == SWAP_B))
			node = node->next;
		if (node && node->action == ac_reverse(action))
			return (node);
	}
	else if (action == SWAP_B || action == ROTATE_B || action == RROTATE_B)
	{
		while (node && (node->action == ROTATE_A || node->action == RROTATE_A
				|| node->action == SWAP_A))
			node = node->next;
		if (node && node->action == ac_reverse(action))
			return (node);
	}
	return (NULL);
}
