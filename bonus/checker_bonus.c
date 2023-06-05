/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:10:25 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/08 13:08:41 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	read_actions(t_sgroup *sg);

int	main(int argc, char **argv)
{
	t_sgroup	*sg;
	int			error;

	error = 0;
	if (argc > 1)
	{
		sg = parse_numbers(&argv[1]);
		if (sg)
		{
			error = read_actions(sg);
			sg_destroy(&sg);
		}
		else
			error = -1;
	}
	if (error == -1)
		ft_put_str(STDERR_FILENO, "Error\n");
	else if (error == 1)
	{
		error = 0;
		ft_put_str(STDOUT_FILENO, "KO\n");
	}
	else if (argc > 1)
		ft_put_str(STDOUT_FILENO, "OK\n");
	return (error);
}

static int	read_actions(t_sgroup *sg)
{
	char	*line;
	int		error;

	error = 0;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		error = operate_stack(sg, line);
		free(line);
		line = NULL;
		if (!error)
			line = get_next_line(STDIN_FILENO);
	}
	if (!error && (sg->stb->count || !st_is_sorted(sg->sta)))
		error = 1;
	return (error);
}
