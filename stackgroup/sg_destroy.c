/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sg_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:15:30 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/24 10:12:11 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackgroup.h"

void	sg_destroy(t_sgroup **sg)
{
	if (!*sg)
		return ;
	ac_destroy(&((*sg)->actions));
	st_destroy(&((*sg)->sta));
	st_destroy(&((*sg)->stb));
	free(*sg);
	*sg = NULL;
}
