/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:06 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/30 19:15:52 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	copy_memory(char *str1, char *str2, size_t length)
{
	size_t	i;

	if (!str1 || !str2 || !length)
		return ;
	i = ft_str_len(str2);
	if (i < length)
		length = i;
	i = 0;
	while (i < length)
	{
		str1[i] = str2[i];
		i++;
	}
}

void	merge_strings(char **str1, char **str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;

	str1_len = ft_str_len(*str1);
	str2_len = ft_str_len(*str2);
	if (str1_len + str2_len > 0)
		new_str = malloc (str1_len + str2_len + 1);
	else
		new_str = NULL;
	if (new_str)
	{
		copy_memory(new_str, *str1, str1_len);
		copy_memory(new_str + str1_len, *str2, str2_len);
		new_str[str1_len + str2_len] = 0;
	}
	free(*str1);
	*str1 = new_str;
	if (str2_len)
		**str2 = 0;
}

int	find_newline(char *str)
{
	size_t	pos;
	int		result;

	result = -1;
	pos = 0;
	if (str)
	{
		while (str[pos] && str[pos] != 10)
			pos++;
		if (str[pos] == 10)
			result = pos;
	}
	return (result);
}
