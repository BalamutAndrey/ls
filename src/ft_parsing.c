/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:51 by eboris            #+#    #+#             */
/*   Updated: 2020/01/31 17:41:30 by eboris           ###   ########.fr       */
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
	kl->programm_name = ft_strdup(argv[0]);
	while ((argc > 1) && (++i < argc) && (argv[i][0] == '-'))
		if ((c = ft_ls_key(kl, argv[i])) != 255)
		{
			//ft_printf("%s: illegal option -- %c\n", argv[0], argv[i][c]);
			//ft_printf("usage: %s [-ACGLRSafglortu1] [file ...]\n", argv[0]);
			ft_print_illegal_option(argv[0], argv[i][c]);
			return (0);
		}
	i--;
	while ((argc > 1) && ++i < argc)
		ft_ls_writedir(kl, argv[i]);
	if (kl->dirnbr == 0)
	{
		kl->first->dir = ft_strdup(".");
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
