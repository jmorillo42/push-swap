/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:42:25 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/27 18:23:41 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../stackgroup/stackgroup.h"

typedef struct s_qsdata
{
	t_sgroup	*sg;
	int			st_id;
	int			min;
	int			max;
	int			pivot;
}	t_qsdata;

int			sort(t_sgroup *sg);
void		sort_two(t_sgroup *sg);
void		sort_three(t_sgroup *sg);

void		sort_greater_three(t_sgroup *sg);
void		sgt_align_stack(t_sgroup *sg);
void		sgt_push_chunks(t_sgroup *sg);
void		sgt_push_back(t_sgroup *sg);

#endif
