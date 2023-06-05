/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_opposite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:34:24 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/25 23:36:08 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	ac_opposite(int action)
{
	if (action == SWAP_A)
		return (SWAP_B);
	else if (action == SWAP_B)
		return (SWAP_A);
	else if (action == ROTATE_A)
		return (ROTATE_B);
	else if (action == ROTATE_B)
		return (ROTATE_A);
	else if (action == RROTATE_A)
		return (RROTATE_B);
	else if (action == RROTATE_B)
		return (RROTATE_A);
	return (-1);
}
