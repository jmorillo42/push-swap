/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackgroup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:31:54 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/30 12:39:49 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKGROUP_H
# define STACKGROUP_H

# include "../stack/stack.h"
# include "../actions/actions.h"

# define STA 0
# define STB 1
# define STALL 2

typedef struct s_stackgroup
{
	t_stack		*sta;
	t_stack		*stb;
	t_actions	*actions;
}	t_sgroup;

t_sgroup	*sg_create(void);
void		sg_destroy(t_sgroup **sg);
void		sg_print(t_sgroup *sg);
void		sg_push(t_sgroup *sg, int stack_id);
void		sg_rotate(t_sgroup *sg, int stack_id);
void		sg_rotate_count(t_sgroup *sg, int st_id, size_t count, int upward);
void		sg_rrotate(t_sgroup *sg, int stack_id);
void		sg_swap(t_sgroup *sg, int stack_id);

#endif
