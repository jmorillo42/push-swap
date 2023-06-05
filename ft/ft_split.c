/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:06:18 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/04 18:45:26 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	next_word_pos(char const *str, size_t pos);
static int	next_space_pos(char const *str, size_t pos);

char	**ft_split(char const *str)
{
	char	**result;
	size_t	i;
	size_t	word_count;
	int		word_pos;
	int		space_pos;

	if (!str)
		return (NULL);
	word_count = ft_count_words(str);
	result = ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (result);
	i = 0;
	space_pos = 0;
	while (i < word_count)
	{
		word_pos = next_word_pos(str, space_pos);
		space_pos = next_space_pos(str, word_pos);
		result[i] = ft_calloc(space_pos - word_pos + 1, sizeof(char));
		if (!result[i])
			return (ft_free_strings(result));
		ft_memcpy(result[i], &str[word_pos], space_pos - word_pos);
		i++;
	}
	return (result);
}

static int	next_word_pos(char const *str, size_t pos)
{
	while (str[pos] == 32)
		pos++;
	if (str[pos])
		return (pos);
	else
		return (-1);
}

static int	next_space_pos(char const *str, size_t pos)
{
	if (!str[pos])
		return (-1);
	while (str[pos] && str[pos] != 32)
		pos++;
	return (pos);
}
