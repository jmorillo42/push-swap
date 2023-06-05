/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:15:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 12:04:22 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	ac_destroy(t_actions **actions)
{
	t_actions	*ac;

	if (!*actions)
		return ;
	ac = *actions;
	while (ac->first)
	{
		ac->last = ac->first;
		ac->first = ac->first->next;
		free(ac->last);
	}
	ac->count = 0;
	ac->first = NULL;
	ac->last = NULL;
	free(*actions);
	*actions = NULL;
}
