/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:59:28 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 20:51:05 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_greater_three(t_sgroup *sg)
{
	sgt_push_chunks(sg);
	sort_three(sg);
	sgt_push_back(sg);
	sgt_align_stack(sg);
}
