/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:15:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/17 09:24:15 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

t_actions	*ac_create(void)
{
	t_actions	*new_actions;

	new_actions = malloc(sizeof(t_actions));
	if (new_actions)
	{
		new_actions->count = 0;
		new_actions->first = NULL;
		new_actions->last = NULL;
	}
	return (new_actions);
}
