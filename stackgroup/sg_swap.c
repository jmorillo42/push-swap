/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:57:44 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 15:43:17 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_swap(t_sgroup *sg, int stack_id)
{
	if (stack_id == STA && sg->sta->count > 1)
	{
		st_swap(sg->sta);
		ac_add(sg->actions, SWAP_A);
	}
	else if (stack_id == STB && sg->stb->count > 1)
	{
		st_swap(sg->stb);
		ac_add(sg->actions, SWAP_B);
	}
	else if (stack_id == STALL && (sg->sta->count > 1 || sg->stb->count > 1))
	{
		st_swap(sg->sta);
		st_swap(sg->stb);
		ac_add(sg->actions, SWAP_ALL);
	}
}
