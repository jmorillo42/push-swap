/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:15:58 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/17 09:46:45 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../ft/ft.h"

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	size_t	count;
	t_list	*first;
	t_list	*last;
}	t_stack;

int		st_add(t_stack *stack, int number);
t_stack	*st_create(void);
void	st_destroy(t_stack **stack);
size_t	st_find(t_stack *stack, int number);
size_t	st_find_next(t_stack *stack, int number);
int		st_is_sorted(t_stack *stack);
int		st_max(t_stack *stack);
int		st_min(t_stack *stack);
t_list	*st_node(t_stack *stack, size_t position);
int		st_number(t_stack *stack, size_t position);
void	st_push(t_stack *source, t_stack *target);
void	st_rotate(t_stack *stack);
void	st_rrotate(t_stack *stack);
void	st_swap(t_stack *stack);

size_t	st_next_num(t_stack *stack, int *number);

#endif
