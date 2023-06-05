/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:01:13 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 21:57:59 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void			rotate_stacks(t_sgroup *sg, unsigned int posa,
						unsigned int posb, unsigned int min_moves);
static void			calc_position_min_moves(t_sgroup *sg, unsigned int *posa,
						unsigned int *posb, unsigned int *min_moves);
static unsigned int	calc_target_position(t_stack *st, int num);
static unsigned int	calc_total_moves(t_sgroup *sg, unsigned int posa,
						unsigned int posb);

void	sgt_push_back(t_sgroup *sg)
{
	unsigned int	posa;
	unsigned int	posb;
	unsigned int	min_moves;

	while (sg->stb->count)
	{
		calc_position_min_moves(sg, &posa, &posb, &min_moves);
		rotate_stacks(sg, posa, posb, min_moves);
		sg_push(sg, STA);
	}
}

static void	rotate_stacks(t_sgroup *sg, unsigned int posa, unsigned int posb,
	unsigned int min_moves)
{
	if (ft_max_num(posa - 1, posb - 1) == (int)min_moves)
	{
		sg_rotate_count(sg, ft_num_if(posa > posb, STA, STB),
			ft_abs(posb - posa), 1);
		sg_rotate_count(sg, STALL, ft_min_num(posa -1, posb - 1), 1);
	}
	else if (ft_max_num(sg->sta->count - posa + 1, sg->stb->count - posb + 1)
		== (int)min_moves)
	{
		sg_rotate_count(sg, ft_num_if(sg->sta->count - posa + 1
				> sg->stb->count - posb + 1, STA, STB), ft_abs(
				(sg->sta->count - posa) - (sg->stb->count - posb)), 0);
		sg_rotate_count(sg, STALL, ft_min_num(sg->sta->count - posa + 1,
				sg->stb->count - posb + 1), 0);
	}
	else if ((posa - 1) + (sg->stb->count - posb + 1) == min_moves)
	{
		sg_rotate_count(sg, STA, posa -1, 1);
		sg_rotate_count(sg, STB, sg->stb->count - posb + 1, 0);
	}
	else if ((posb -1) + (sg->sta->count - posa + 1) == min_moves)
	{
		sg_rotate_count(sg, STB, posb -1, 1);
		sg_rotate_count(sg, STA, sg->sta->count - posa + 1, 0);
	}
}

static void	calc_position_min_moves(t_sgroup *sg, unsigned int *posa,
	unsigned int *posb, unsigned int *min_moves)
{
	t_list			*l;
	unsigned int	pos;
	unsigned int	moves;
	unsigned int	target_pos;

	l = sg->stb->first;
	*posa = 0;
	*posb = 0;
	*min_moves = sg->stb->count + sg->sta->count;
	pos = 1;
	while (l)
	{
		target_pos = calc_target_position(sg->sta, l->number);
		moves = calc_total_moves(sg, target_pos, pos);
		if (moves < *min_moves)
		{
			*posa = target_pos;
			*posb = pos;
			*min_moves = moves;
		}
		l = l->next;
		pos++;
	}
}

static unsigned int	calc_target_position(t_stack *st, int num)
{
	t_list			*l;
	unsigned int	pos;
	int				min_num;
	int				max_num;

	l = st->first;
	min_num = st_min(st);
	max_num = st_max(st);
	if ((num < l->number && (l->number == min_num || num > st->last->number))
		|| (num > max_num && max_num == st->last->number))
		return (1);
	pos = 2;
	while (l && l->next)
	{
		if ((num > l->number && num < l->next->number)
			|| (l->number > l->next->number
				&& (num < min_num || num > max_num)))
			return (pos);
		l = l->next;
		pos++;
	}
	return (0);
}

static unsigned int	calc_total_moves(t_sgroup *sg, unsigned int posa,
	unsigned int posb)
{
	unsigned int	rr;
	unsigned int	rrr;
	unsigned int	rb_rra;
	unsigned int	ra_rrb;

	rr = ft_max_num(posa - 1, posb - 1);
	rrr = ft_max_num(sg->sta->count + 1 - posa,
			sg->stb->count + 1 - posb);
	ra_rrb = (posa - 1) + (sg->stb->count + 1 - posb);
	rb_rra = (posb - 1) + (sg->sta->count + 1 - posa);
	return (ft_min_num(ft_min_num(rr, rrr), ft_min_num(ra_rrb, rb_rra)));
}
