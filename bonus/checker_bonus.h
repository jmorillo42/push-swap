/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:10:22 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/30 20:26:10 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../stackgroup/stackgroup.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

t_sgroup	*parse_numbers(char **arguments);
int			operate_stack(t_sgroup *sg, char *line);
char		*get_next_line(int fd);
void		copy_memory(char *str1, char *str2, size_t length);
void		merge_strings(char **str1, char **str2);
int			find_newline(char *str);
char		*split_string(char **str);

#endif
