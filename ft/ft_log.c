/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:06:38 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/28 21:27:17 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_log(int number)
{
	int	result;

	result = 0;
	while (number > 0)
	{
		number = number / 2;
		result++;
	}
	return (result);
}
