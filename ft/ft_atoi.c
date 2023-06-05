/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:48:01 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/02 19:23:43 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#define MAXDIGIT 10
#define ZERO 48
#define NINE 57

static int	is_number(const char *str);

int	ft_atoi(const char *str, int *number)
{
	int		i;
	long	result;
	int		sign;

	if (!is_number(str))
		return (0);
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - ZERO);
		i++;
	}
	result *= sign;
	*number = (int) result;
	return (result == (long) *number);
}

static int	is_number(const char *str)
{
	int		i;
	size_t	length;

	if (!str || !ft_str_len(str))
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!ft_str_len(str + i))
		return (0);
	while (str[i] == ZERO)
		i++;
	length = ft_str_len(str + i);
	if (length > MAXDIGIT)
		return (0);
	while (str[i] >= ZERO && str[i] <= NINE)
		i++;
	return (!str[i]);
}
