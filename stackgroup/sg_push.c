/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:49:41 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 15:44:07 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_push(t_sgroup *sg, int stack_id)
{
	if (stack_id == STA && sg->stb->count)
	{
		st_push(sg->stb, sg->sta);
		ac_add(sg->actions, PUSH_A);
	}
	else if (stack_id == STB && sg->sta->count)
	{
		st_push(sg->sta, sg->stb);
		ac_add(sg->actions, PUSH_B);
	}
}
