/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:49:59 by eboris            #+#    #+#             */
/*   Updated: 2020/01/24 14:28:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYLIST_H
# define KEYLIST_H

# include <stdlib.h>

typedef struct				s_dirkeylist
{
	char					*dir;
	struct s_dirkeylist		*next;
}							t_dirkeylist;

typedef struct				s_keylist
{
	int						l;
	int						r_big;
	int						a;
	int						r;
	int						t;
	int						u;
	int						f;
	int						g;
	int						a_big;
	int						l_big;
	int						o;
	int						s_big;
	int						g_big;
	t_dirkeylist			*first;
	t_dirkeylist			*current;
	t_dirkeylist			*end;
	int						dirnbr;
}							t_keylist;

t_keylist					*create_keylist(void);
t_dirkeylist				*create_dirkeylist(void);
t_dirkeylist				*add_dkl(t_keylist *kl);
void						remove_list(t_keylist *kl);

#endif
