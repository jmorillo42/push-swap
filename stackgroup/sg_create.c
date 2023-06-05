/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:13:14 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/17 14:09:25 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

t_sgroup	*sg_create(void)
{
	t_sgroup	*sg;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_actions	*actions;

	sg = malloc(sizeof(t_sgroup));
	stack_a = st_create();
	stack_b = st_create();
	actions = ac_create();
	if (sg && stack_a && stack_b && actions)
	{
		sg->sta = stack_a;
		sg->stb = stack_b;
		sg->actions = actions;
	}
	else
	{
		sg_destroy(&sg);
		st_destroy(&stack_a);
		st_destroy(&stack_b);
		ac_destroy(&actions);
	}
	return (sg);
}
