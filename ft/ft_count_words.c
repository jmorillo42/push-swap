/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:06:18 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/04 18:47:46 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_count_words(char const *str)
{
	size_t			count;
	unsigned short	is_sep;

	count = 0;
	is_sep = 1;
	while (*str)
	{
		if (*str == 32 && !is_sep)
			is_sep = 1;
		else if (*str != 32 && is_sep)
		{
			is_sep = 0;
			count++;
		}
		str++;
	}
	return (count);
}
