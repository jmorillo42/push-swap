/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:03:59 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 08:52:11 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*ptr_aux;
	size_t			i;

	ptr = malloc(count * size);
	if (ptr)
	{
		ptr_aux = ptr;
		i = 0;
		while (i < count * size)
		{
			ptr_aux[i] = 0;
			i++;
		}
	}
	return (ptr);
}
