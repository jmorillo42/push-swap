/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:55:56 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 18:57:06 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num_if(int condition, int value1, int value2)
{
	if (condition)
		return (value1);
	return (value2);
}
