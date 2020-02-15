/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:36 by eboris            #+#    #+#             */
/*   Updated: 2020/02/15 19:04:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_keylist		*create_keylist(void)
{
	t_keylist	*kl;

	kl = (t_keylist *)malloc(sizeof(t_keylist));
	if (!kl)
		return (NULL);
	kl->l = 0;
	kl->r_big = 0;
	kl->a = 0;
	kl->r = 0;
	kl->t = 0;
	kl->u = 0;
	kl->f = 0;
	kl->g = 0;
	kl->a_big = 0;
	kl->l_big = 0;
	kl->o = 0;
	kl->s_big = 0;
	kl->g_big = 0;
	kl->first = create_dirkeylist();
	if (!kl->first)
		return (NULL);
	create_keylist_1(kl);
	return (kl);
}

void			create_keylist_1(t_keylist *kl)
{
	kl->x = 0;
	kl->current = kl->first;
	kl->end = kl->first;
	kl->dirnbr = 0;
	kl->isfile = 0;
	kl->t_first = NULL;
	kl->maxsize = NULL;
}

t_dirkeylist	*create_dirkeylist(void)
{
	t_dirkeylist	*dkl;

	dkl = (t_dirkeylist *)malloc(sizeof(t_dirkeylist));
	if (!dkl)
		return (NULL);
	dkl->dir = NULL;
	dkl->next = NULL;
	return (dkl);
}

t_dirkeylist	*add_dkl(t_keylist *kl)
{
	t_dirkeylist	*dkl;

	dkl = create_dirkeylist();
	if (!dkl)
		return (NULL);
	kl->end->next = dkl;
	kl->dirnbr += 1;
	return (dkl);
}

void			remove_list(t_keylist *kl)
{
	int				i;
	t_dirkeylist	*tempdir1;
	t_dirkeylist	*tempdir2;

	i = 0;
	tempdir1 = kl->first;
	while (++i <= kl->dirnbr)
	{
		free(tempdir1->dir);
		tempdir2 = tempdir1->next;
		free(tempdir1);
		tempdir1 = tempdir2;
	}
	if (kl->programm_name)
		ft_strdel(&kl->programm_name);
	if (kl->maxsize)
		free(kl->maxsize);
	kl->maxsize = NULL;
	free(kl);
}
