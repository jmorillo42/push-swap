/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:05 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/08 13:03:12 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	operate_stack(t_sgroup *sg, char *line)
{
	if (ft_str_cmp(line, "pa\n") == 0)
		sg_push(sg, STA);
	else if (ft_str_cmp(line, "pb\n") == 0)
		sg_push(sg, STB);
	else if (ft_str_cmp(line, "sa\n") == 0)
		sg_swap(sg, STA);
	else if (ft_str_cmp(line, "sb\n") == 0)
		sg_swap(sg, STB);
	else if (ft_str_cmp(line, "ss\n") == 0)
		sg_swap(sg, STALL);
	else if (ft_str_cmp(line, "ra\n") == 0)
		sg_rotate(sg, STA);
	else if (ft_str_cmp(line, "rb\n") == 0)
		sg_rotate(sg, STB);
	else if (ft_str_cmp(line, "rr\n") == 0)
		sg_rotate(sg, STALL);
	else if (ft_str_cmp(line, "rra\n") == 0)
		sg_rrotate(sg, STA);
	else if (ft_str_cmp(line, "rrb\n") == 0)
		sg_rrotate(sg, STB);
	else if (ft_str_cmp(line, "rrr\n") == 0)
		sg_rrotate(sg, STALL);
	else
		return (-1);
	return (0);
}
