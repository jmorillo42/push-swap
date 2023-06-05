/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_align_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:51:19 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 20:58:11 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sgt_align_stack(t_sgroup *sg)
{
	unsigned int	min_pos;

	min_pos = st_find(sg->sta, st_min(sg->sta));
	if (min_pos - 1 < sg->sta->count + 1 - min_pos)
		sg_rotate_count(sg, STA, min_pos - 1, 1);
	else
		sg_rotate_count(sg, STA, sg->sta->count + 1 - min_pos, 0);
}
