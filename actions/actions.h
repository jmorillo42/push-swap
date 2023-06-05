/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorillo <jmorillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:15:58 by jmorillo          #+#    #+#             */
/*   Updated: 2022/09/27 19:07:34 by jmorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "../ft/ft.h"

# define PUSH_A 1
# define PUSH_B 2
# define SWAP_ALL 10
# define SWAP_A 11
# define SWAP_B 12
# define ROTATE_ALL 20
# define ROTATE_A 21
# define ROTATE_B 22
# define RROTATE_ALL 30
# define RROTATE_A 31
# define RROTATE_B 32

typedef struct s_dlist
{
	int				action;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_actions
{
	size_t	count;
	t_dlist	*first;
	t_dlist	*last;
}	t_actions;

int			ac_add(t_actions *actions, int action);
void		ac_clean(t_actions *ac);
t_actions	*ac_create(void);
void		ac_destroy(t_actions **actions);
t_dlist		*ac_find_opposite(t_dlist *node);
t_dlist		*ac_find_reverse(t_dlist *node);
int			ac_opposite(int action);
void		ac_remove(t_actions *actions, t_dlist *node);
int			ac_reverse(int action);

#endif
