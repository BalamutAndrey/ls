/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:36 by eboris            #+#    #+#             */
/*   Updated: 2020/01/22 16:44:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keylist.h"

t_keylist	*create_keylist(void)
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
	return (kl);
}
