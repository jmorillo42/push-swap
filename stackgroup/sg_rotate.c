/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:42 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 15:41:25 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_rotate(t_sgroup *sg, int stack_id)
{
	if (stack_id == STA && sg->sta->count > 1)
	{
		st_rotate(sg->sta);
		ac_add(sg->actions, ROTATE_A);
	}
	else if (stack_id == STB && sg->stb->count > 1)
	{
		st_rotate(sg->stb);
		ac_add(sg->actions, ROTATE_B);
	}
	else if (stack_id == STALL && (sg->sta->count > 1 || sg->stb->count > 1))
	{
		st_rotate(sg->sta);
		st_rotate(sg->stb);
		ac_add(sg->actions, ROTATE_ALL);
	}
}
