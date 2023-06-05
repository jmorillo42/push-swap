/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:27:34 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/25 22:12:29 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int	ac_reverse(int action)
{
	if (action == SWAP_A)
		return (SWAP_A);
	else if (action == SWAP_B)
		return (SWAP_B);
	else if (action == SWAP_ALL)
		return (SWAP_ALL);
	else if (action == PUSH_A)
		return (PUSH_B);
	else if (action == PUSH_B)
		return (PUSH_A);
	else if (action == ROTATE_A)
		return (RROTATE_A);
	else if (action == ROTATE_B)
		return (RROTATE_B);
	else if (action == RROTATE_A)
		return (ROTATE_A);
	else if (action == RROTATE_B)
		return (ROTATE_B);
	else if (action == ROTATE_ALL)
		return (RROTATE_ALL);
	else if (action == RROTATE_ALL)
		return (ROTATE_ALL);
	return (-1);
}
