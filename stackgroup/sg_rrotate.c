/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:39 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 15:42:06 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_rrotate(t_sgroup *sg, int stack_id)
{
	if (stack_id == STA && sg->sta->count > 1)
	{
		st_rrotate(sg->sta);
		ac_add(sg->actions, RROTATE_A);
	}
	else if (stack_id == STB && sg->stb->count > 1)
	{
		st_rrotate(sg->stb);
		ac_add(sg->actions, RROTATE_B);
	}
	else if (stack_id == STALL && (sg->sta->count > 1 || sg->stb->count > 1))
	{
		st_rrotate(sg->sta);
		st_rrotate(sg->stb);
		ac_add(sg->actions, RROTATE_ALL);
	}
}
