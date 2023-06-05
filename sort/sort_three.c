/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:14:25 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 19:07:01 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_three(t_sgroup *sg)
{
	size_t	pos_min;
	size_t	pos_max;

	if (!sg || sg->sta->count != 3 || st_is_sorted(sg->sta))
		return ;
	pos_min = st_find(sg->sta, st_min(sg->sta));
	pos_max = st_find(sg->sta, st_max(sg->sta));
	if (pos_min == 1 && pos_max == 2)
	{
		sg_rrotate(sg, STA);
		sg_swap(sg, STA);
	}
	else if (pos_min == 2 && pos_max == 1)
		sg_rotate(sg, STA);
	else if (pos_min == 2 && pos_max == 3)
		sg_swap(sg, STA);
	else if (pos_min == 3 && pos_max == 2)
		sg_rrotate(sg, STA);
	else if (pos_min == 3 && pos_max == 1)
	{
		sg_rotate(sg, STA);
		sg_swap(sg, STA);
	}
}
