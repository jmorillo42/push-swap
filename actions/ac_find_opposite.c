/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_find_opposite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:13:59 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 19:44:33 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static t_dlist	*find_oppo(t_dlist *node, int action, int ignore1, int ignore2);

t_dlist	*ac_find_opposite(t_dlist *node)
{
	int		action;
	t_dlist	*result;

	action = node->action;
	node = node->next;
	result = NULL;
	if (action == SWAP_A)
		result = find_oppo(node, SWAP_A, ROTATE_A, RROTATE_A);
	else if (action == SWAP_B)
		result = find_oppo(node, SWAP_B, ROTATE_B, RROTATE_B);
	else if (action == ROTATE_A)
		result = find_oppo(node, ROTATE_A, RROTATE_A, SWAP_A);
	else if (action == ROTATE_B)
		result = find_oppo(node, ROTATE_B, RROTATE_B, SWAP_B);
	else if (action == RROTATE_A)
		result = find_oppo(node, RROTATE_A, ROTATE_A, SWAP_A);
	else if (action == RROTATE_B)
		result = find_oppo(node, RROTATE_B, ROTATE_B, SWAP_B);
	return (result);
}

static t_dlist	*find_oppo(t_dlist *node, int action, int ignore1, int ignore2)
{
	while (node && (node->action == action
			|| node->action == ignore1 || node->action == ignore2))
		node = node->next;
	if (node && node->action == ac_opposite(action))
		return (node);
	return (NULL);
}
