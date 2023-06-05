/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:25:19 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/08 11:25:07 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	parse_quoted(t_stack *stack, char *argument);
static int	add_number(t_stack *stack, char *num_str);
static int	calc_new_number(t_stack *stack, int number);
static int	renumber_stack(t_sgroup *sg);

t_sgroup	*parse_numbers(char **arguments)
{
	int			i;
	t_sgroup	*sg;
	int			error;

	error = 0;
	sg = sg_create();
	if (!sg)
		return (NULL);
	i = 0;
	while (arguments[i] && !error)
	{
		if (!add_number(sg->sta, arguments[i])
			&& !parse_quoted(sg->sta, arguments[i]))
			error = 1;
		i++;
	}
	if (error || !renumber_stack(sg))
		sg_destroy(&sg);
	return (sg);
}

static int	add_number(t_stack *stack, char *num_str)
{
	int	num;

	if (ft_atoi(num_str, &num) && !st_find(stack, num))
		return (st_add(stack, num));
	return (0);
}

static int	parse_quoted(t_stack *stack, char *argument)
{
	char	**words;
	int		i;
	size_t	count;

	count = ft_count_words(argument);
	if (!count)
		return (0);
	words = ft_split(argument);
	i = 0;
	while (words[i])
	{
		if (!add_number(stack, words[i]))
		{
			words = ft_free_strings(words);
			return (0);
		}
		i++;
	}
	words = ft_free_strings(words);
	return (1);
}

static int	renumber_stack(t_sgroup *sg)
{
	t_stack	*new_stack;
	t_list	*node;
	int		ok;

	if (!sg->sta->count)
		return (1);
	new_stack = st_create();
	if (!new_stack)
		return (0);
	ok = 1;
	node = st_node(sg->sta, 1);
	while (node && ok)
	{
		if (!st_add(new_stack, calc_new_number(sg->sta, node->number)))
			ok = 0;
		node = node->next;
	}
	if (!ok)
		st_destroy(&new_stack);
	else
	{
		st_destroy(&(sg->sta));
		sg->sta = new_stack;
	}
	return (ok);
}

static int	calc_new_number(t_stack *stack, int number)
{
	t_list	*element;
	int		new_num;

	element = st_node(stack, 1);
	new_num = 1;
	while (element)
	{
		if (number > element->number)
			new_num++;
		element = element->next;
	}
	return (new_num);
}
