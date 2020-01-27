/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:51 by eboris            #+#    #+#             */
/*   Updated: 2020/01/27 13:35:31 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_keylist	*ft_ls_parsing_key(int argc, char **argv)
{
	t_keylist	*kl;
	int			i;
	int			c;

	i = 0;
	if (!(kl = create_keylist()))
		return (NULL);
	while ((argc > 1) && (++i < argc) && (argv[i][0] == '-'))
		if ((c = ft_ls_key(kl, argv[i])) != 255)
		{
			ft_printf("%s: illegal option -- %c\n", argv[0], argv[i][c]);
			ft_printf("usage: %s [-ACGLRSafglortu1] [file ...]\n", argv[0]);
			return (0);
		}
	i--;
	while ((argc > 1) && ++i < argc)
		ft_ls_writedir(kl, argv[i]);
	if (kl->dirnbr == 0)
	{
		kl->first->dir = strdup(".");
		kl->dirnbr = 1;
	}
	return (kl);
}

void		ft_ls_writedir(t_keylist *kl, char *argv)
{
	if (kl->dirnbr == 0)
	{
		kl->first->dir = ft_strdup(argv);
		kl->dirnbr = 1;
	}
	else
	{
		kl->end = add_dkl(kl);
		kl->end->dir = ft_strdup(argv);
	}
}

int			ft_ls_key(t_keylist *kl, char *argv)
{
	int	i;

	i = 1;
	while (argv[i] != '\0')
	{
		if (ft_ls_key_if_1(kl, argv[i]) == 1)
			i++;
		else
			return (i);
	}
	return (255);
}

int			ft_ls_key_if_1(t_keylist *kl, char k)
{
	if (k == 'l')
	{
		kl->one = 0;
		kl->l = 1;
		kl->c_big = 0;
	}
	else if (k == 'R')
		kl->r_big = 1;
	else if (k == 'a')
		kl->a = 1;
	else if (k == 'r')
		kl->r = 1;
	else if (k == 't')
		kl->t = 1;
	else if (k == 'u')
		kl->u = 1;
	else if (k == 'f')
		kl->f = 1;
	else if (k == 'g')
		kl->g = 1;
	else if (k == 'A')
		kl->a_big = 1;
	else
		return (ft_ls_key_if_2(kl, k));
	return (1);
}

int			ft_ls_key_if_2(t_keylist *kl, char k)
{
	if (k == 'G')
		kl->g_big = 1;
	else if (k == 'L')
		kl->l_big = 1;
	else if (k == 'o')
		kl->o = 1;
	else if (k == 'S')
		kl->s_big = 1;
	else if (k == '1')
	{
		kl->one = 1;
		kl->l = 0;
		kl->c_big = 0;
	}
	else if (k == 'C')
	{
		kl->one = 0;
		kl->l = 0;
		kl->c_big = 1;
	}
	else
		return (0);
	return (1);
}
