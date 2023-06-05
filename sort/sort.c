/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:11:09 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 15:57:20 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	sort(t_sgroup *sg)
{
	int	ok;

	ok = 1;
	if (st_is_sorted(sg->sta))
		return (ok);
	if (sg->sta->count == 2)
		sort_two(sg);
	else if (sg->sta->count == 3)
		sort_three(sg);
	else
		sort_greater_three(sg);
	if (ok)
		ac_clean(sg->actions);
	return (ok);
}
