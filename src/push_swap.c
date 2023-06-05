/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:34:23 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/29 10:16:01 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (sort(sg))
				sg_print(sg);
			else
				error = 1;
			sg_destroy(&sg);
		}
		else
			error = 1;
	}
	if (error)
		ft_put_str(STDERR_FILENO, "Error\n");
	return (error);
}
