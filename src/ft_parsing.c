/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:29:51 by eboris            #+#    #+#             */
/*   Updated: 2020/02/16 16:55:46 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_keylist	*ft_ls_parsing_key(int argc, char **argv)
{
	t_keylist	*kl;
	int			i;
	int			c;

	i = 1;
	c = 0;
	if (!(kl = create_keylist()))
		return (NULL);
	kl->programm_name = ft_strdup(argv[0]);
	while ((argc > 1) && (i < argc) && (argv[i][0] == '-') && (c != '-'))
	{
		if ((c = ft_ls_key(kl, argv[i])) != 255)
		{
			if (c != '-')
			{
				ft_print_illegal_option(argv[0], argv[i][c]);
				remove_list(kl);
				return (0);
			}
			else if ((c == '-') && (argv[i][1] == '\0'))
				i--;
		}
		i++;
	}
	return (ft_parsing_dir(kl, argc, argv, (i - 1)));
}

t_keylist	*ft_parsing_dir(t_keylist *kl, int argc, char **argv, int i)
{
	int	a;

	a = 1;
	while ((argc > 1) && ++i < argc)
		a = ft_ls_writedir(kl, argv[i]);
	if ((kl->dirnbr == 0) && (kl->t_first == NULL) && (a != 0))
	{
		kl->first->dir = ft_strdup(".");
		kl->dirnbr = 1;
	}
	if (kl->first != NULL)
		ft_sort_arg_dirs(kl);
	if ((kl->t_first != NULL))
	{
		ft_dir_sort_print(kl, kl->t_first);
		if (kl->dirnbr > 0)
			ft_printf("\n");
		kl->t_first = NULL;
	}
	return (kl);
}

int			ft_ls_key(t_keylist *kl, char *argv)
{
	int	i;

	i = 1;
	if (((argv[0] == 45) && (argv[1] == '\0')) ||
		((argv[1] == 45) && (argv[2] == '\0')))
		return (45);
	while (argv[i] != '\0')
	{
		if (ft_ls_key_if_1(kl, argv[i]) == 1)
			i++;
		else
			return (i);
	}
	return (255);
}
