/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:21:42 by eboris            #+#    #+#             */
/*   Updated: 2020/01/27 13:15:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <stdio.h> //remove

int	main(int argc, char **argv)
{
	t_keylist	*kl;
	int			i;
	
	if (!(kl = ft_ls_parsing_key(argc, argv)))
	{
		return (0);
	}

/*
	printf("l = %i\n", kl->l);
	printf("R = %i\n", kl->r_big);
	printf("a = %i\n", kl->a);
	printf("r = %i\n", kl->r);
	printf("t = %i\n", kl->t);
	printf("u = %i\n", kl->u);
	printf("f = %i\n", kl->f);
	printf("g = %i\n", kl->g);
	printf("A = %i\n", kl->a_big);
	printf("L = %i\n", kl->l_big);
	printf("o = %i\n", kl->o);
	printf("G = %i\n", kl->g_big);
	printf("S = %i\n", kl->s_big);
	printf("1 = %i\n", kl->one);
	printf("C = %i\n", kl->c_big);

	printf("===========\n");
	int i;
	i = 1;
	kl->current = kl->first;
	while (i <= kl->dirnbr)
	{
		printf("i = %i; dir = %s\n", i, kl->current->dir);
		kl->current = kl->current->next;
		i++;
	}
*/

	i = 0;
	kl->current = kl->first;
	while (++i <= kl->dirnbr)
	{
		ft_open_and_read_dir(kl->current->dir);
		kl->current = kl->current->next;
	}


	remove_list(kl);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	char	*curdir;
	int		res;

	if (argc > 1 || argv[0] == NULL)
		argc = 2;
	if (!(curdir = ft_strdup("test")))
		return (0);
	res = ft_open_and_read_dir(curdir);
	ft_strdel(&curdir);
	return (0);
}
*/