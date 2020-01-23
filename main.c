/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:21:42 by eboris            #+#    #+#             */
/*   Updated: 2020/01/23 15:33:53 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <stdio.h> //remove

int	main(int argc, char **argv)
{
	t_keylist	*kl;
	//int			res;
	//char		*str;
	
	if (!(kl = ft_ls_parsing_key(argc, argv)))
	{
		//printf("ERROR!\n"); //fix to ft_
		return (0);
	}
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
	//str = ft_strdup(".");
	//res = ft_open_and_read_dir(str);
	return (0);
}

/*
int		main(void)
{
	char	*curdir;
	int		res;

	if (!(curdir = ft_strdup("test")))
		return (0);
	res = ft_open_and_read_dir(curdir);
	ft_strdel(&curdir);
	return (0);
}*/
