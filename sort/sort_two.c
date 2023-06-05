/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:14:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/17 15:17:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_two(t_sgroup *sg)
{
	if (sg && sg->sta->count == 2
		&& st_number(sg->sta, 1) > st_number(sg->sta, 2))
		sg_swap(sg, STA);
}
