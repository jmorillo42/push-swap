/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:24:49 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 11:26:09 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_contains_num(int *numbers, int num)
{
	int	i;

	i = 0;
	while (numbers[i] && numbers[i] != num)
		i++;
	return (numbers[i] == num);
}
