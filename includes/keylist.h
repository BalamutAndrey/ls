/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:49:59 by eboris            #+#    #+#             */
/*   Updated: 2020/01/22 16:09:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYLIST_H
# define KEYLIST_H

# include <stdlib.h>

typedef struct	s_keylist
{
	int			l;
	int			r_big;
	int			a;
	int			r;
	int			t;
	int			u;
	int			f;
	int			g;
	int			a_big;
	int			l_big;
	int			o;
	int			s_big;
	int			g_big;
}				t_keylist;

t_keylist		*create_keylist(void);

#endif
