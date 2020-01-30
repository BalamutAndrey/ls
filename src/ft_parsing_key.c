/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:09:04 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 17:34:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls_key_if_1(t_keylist *kl, char k)
{
	if (k == 'R')
		kl->r_big = 1;
	else if (k == 'r')
		kl->r = 1;
	else if (k == 't')
	{
		kl->t = 1;
		kl->u = 0;
	}
	else if (k == 'u')
	{
		kl->u = 1;
		kl->t = 0;
	}
	else
		return (ft_ls_key_if_2(kl, k));
	return (1);
}

int			ft_ls_key_if_2(t_keylist *kl, char k)
{
	if (k == 'G')
		kl->g_big = 1;
	else if (k == 'f')
		kl->f = 1;
	else if (k == 'g')
	{
		kl->g = 1;
		kl->l = 1;
	}
	else if (k == 'L')
		kl->l_big = 1;
	else if (k == 'o')
	{
		kl->o = 1;
		kl->l = 1;
	}
	else if (k == 'S')
		kl->s_big = 1;
	else
		return (ft_ls_key_if_3(kl, k));
	return (1);
}

int			ft_ls_key_if_3(t_keylist *kl, char k)
{
	if (k == 'a')
	{
		kl->a = 1;
		kl->a_big = 0;
	}
	else if (k == 'A')
	{
		kl->a_big = 1;
		kl->a = 0;
	}
	else if (k == '1')
	{
		kl->one = 1;
		kl->l = 0;
		kl->c_big = 0;
		kl->x = 0;
	}
	else
		return (ft_ls_key_if_4(kl, k));
	return (1);
}

int			ft_ls_key_if_4(t_keylist *kl, char k)
{
	if (k == 'x')
	{
		kl->x = 1;
		kl->c_big = 0;
		kl->one = 0;
		kl->l = 0;
	}
	else if (k == 'C')
	{
		kl->c_big = 1;
		kl->one = 0;
		kl->l = 0;
		kl->x = 0;
	}
	else if (k == 'l')
	{
		kl->l = 1;
		kl->one = 0;
		kl->c_big = 0;
		kl->x = 0;
	}
	else
		return (0);
	return (1);
}
