/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:15:46 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 10:16:24 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

static void	print_action(int action);

void	sg_print(t_sgroup *sg)
{
	t_dlist	*node;

	node = sg->actions->first;
	while (node)
	{
		print_action(node->action);
		node = node->next;
	}
}

static void	print_action(int action)
{
	if (action == PUSH_A)
		ft_put_str(1, "pa\n");
	else if (action == PUSH_B)
		ft_put_str(1, "pb\n");
	else if (action == SWAP_A)
		ft_put_str(1, "sa\n");
	else if (action == SWAP_B)
		ft_put_str(1, "sb\n");
	else if (action == SWAP_ALL)
		ft_put_str(1, "ss\n");
	else if (action == ROTATE_A)
		ft_put_str(1, "ra\n");
	else if (action == ROTATE_B)
		ft_put_str(1, "rb\n");
	else if (action == ROTATE_ALL)
		ft_put_str(1, "rr\n");
	else if (action == RROTATE_A)
		ft_put_str(1, "rra\n");
	else if (action == RROTATE_B)
		ft_put_str(1, "rrb\n");
	else if (action == RROTATE_ALL)
		ft_put_str(1, "rrr\n");
}
