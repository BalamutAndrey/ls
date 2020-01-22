/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:51 by eboris            #+#    #+#             */
/*   Updated: 2020/01/22 18:30:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include <stdio.h> //remove

t_keylist	*ft_ls_parsing_key(int argc, char **argv)
{
	t_keylist	*kl;
	int			i;

	i = 1;
	if (!(kl = create_keylist()))
		return (NULL);
	while ((argc > 1) && i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_ls_key(kl, argv[i]) == 1)
				i++;
			else
			{
				printf("ErrorKEY!!!"); // Fix to ft_printf
				return (0);
			}
		}
	}
	return (kl);
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
			return (0);
	}
	return (1);
}

int			ft_ls_key_if_1(t_keylist *kl, char k)
{
	if (k == 'l')
		kl->l = 1;
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
	else if (k == 'L')
		kl->l_big = 1;
	else if (k == 'o')
		kl->o = 1;
	else
		return (ft_ls_key_if_2(kl, k));
	return (1);
}

int			ft_ls_key_if_2(t_keylist *kl, char k)
{
	if (k == 'G')
		kl->g_big = 1;
	else if (k == 'S')
		kl->s_big = 1;
	else
		return (0);
	return (1);
}