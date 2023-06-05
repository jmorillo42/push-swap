/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_push_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:01:16 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 22:24:35 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void			push_min_moves_number(t_sgroup *sg, int max_number);
static unsigned int	calc_position_min_moves(t_sgroup *sg, int max_number);

void	sgt_push_chunks(t_sgroup *sg)
{
	int	i;
	int	last;
	int	chunks;
	int	count;

	count = (int)sg->sta->count;
	chunks = ft_log(ft_log(count)) - 1;
	i = 1;
	while (i <= chunks)
	{
		last = (i * count) / chunks;
		while ((int)sg->sta->count > 3 && st_min(sg->sta) <= last)
		{
			push_min_moves_number(sg, last);
			if (sg->stb->first->number < last - (count / chunks) / 2)
				sg_rotate(sg, STB);
		}
		i++;
	}
}

static void	push_min_moves_number(t_sgroup *sg, int max_number)
{
	unsigned int	min_pos;

	min_pos = calc_position_min_moves(sg, max_number);
	if (min_pos <= (sg->sta->count / 2) + 1)
		sg_rotate_count(sg, STA, min_pos - 1, 1);
	else
		sg_rotate_count(sg, STA, sg->sta->count - min_pos + 1, 0);
	sg_push(sg, STB);
}

static unsigned int	calc_position_min_moves(t_sgroup *sg, int max_number)
{
	t_list			*l;
	unsigned int	pos;
	unsigned int	min_pos;
	unsigned int	min_moves;

	l = sg->sta->first;
	min_pos = 0;
	min_moves = sg->sta->count;
	pos = 1;
	while (l)
	{
		if (l->number <= max_number)
		{
			if (min_moves > pos -1 || min_moves > sg->sta->count - pos + 1)
			{
				min_pos = pos;
				min_moves = ft_min_num(pos -1, sg->sta->count - pos + 1);
			}
		}
		l = l->next;
		pos++;
	}
	return (min_pos);
}
