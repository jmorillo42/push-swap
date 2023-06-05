/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_rotate_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:35:15 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/30 13:15:07 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_rotate_count(t_sgroup *sg, int st_id, size_t count, int upward)
{
	while (count)
	{
		if (upward)
			sg_rotate(sg, st_id);
		else
			sg_rrotate(sg, st_id);
		count--;
	}
}
