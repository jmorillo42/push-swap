/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:53:47 by jmorillo          #+#    #+#             */
/*   Updated: 2022/11/24 19:06:04 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

int			ft_abs(int num);
int			ft_atoi(const char *str, int *number);
void		*ft_calloc(size_t count, size_t size);
int			ft_contains_num(int *numbers, int num);
size_t		ft_count_words(char const *str);
char		**ft_free_strings(char **strings);
int			ft_in_range(int number, int min_num, int max_num);
int			ft_log(int number);
char		*ft_memcpy(char *dst, const char *src, size_t n);
int			ft_max_num(int n1, int n2);
int			ft_min_num(int n1, int n2);
int			ft_num_if(int condition, int value1, int value2);
int			ft_put_str(int fd, char *str);
char		**ft_split(char const *str);
int			ft_str_cmp(const char *s1, const char *s2);
size_t		ft_str_len(const char *str);

#endif
