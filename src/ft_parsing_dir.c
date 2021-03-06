/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:40:55 by eboris            #+#    #+#             */
/*   Updated: 2020/02/16 16:58:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_writedir(t_keylist *kl, char *argv)
{
	DIR				*dir;
	struct stat		buff;

	dir = NULL;
	lstat(argv, &buff);
	if ((S_ISDIR(buff.st_mode)) || ((S_ISLNK(buff.st_mode)) &&
		((kl->l != 1) || (kl->l_big == 1))))
	{
		dir = ft_check_link_if(kl, argv, buff);
	}
	else if ((S_ISBLK(buff.st_mode)) || (S_ISCHR(buff.st_mode)) ||
				(S_ISFIFO(buff.st_mode)) || (S_ISREG(buff.st_mode)) ||
				(S_ISLNK(buff.st_mode)) || (S_ISSOCK(buff.st_mode)))
		ft_create_tempdir(kl, argv);
	else
		dir = ft_ls_writedir_open(kl, argv);
	if (dir == NULL)
		return (0);
	else
		closedir(dir);
	return (1);
}

DIR		*ft_ls_writedir_open(t_keylist *kl, char *argv)
{
	DIR				*dir;

	dir = opendir(argv);
	if (dir != NULL)
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
	else
	{
		ft_print_error(kl, argv);
	}
	return (dir);
}

DIR		*ft_check_link_if(t_keylist *kl, char *argv, struct stat buff)
{
	char	*linkto;
	DIR		*dir;

	dir = NULL;
	linkto = NULL;
	if ((S_ISDIR(buff.st_mode)) || ((linkto = ft_check_link(argv)) != NULL))
	{
		if (linkto != NULL)
		{
			dir = ft_ls_writedir_open(kl, argv);
			ft_strdel(&linkto);
		}
		else
			dir = ft_ls_writedir_open(kl, argv);
	}
	else
		ft_create_tempdir(kl, argv);
	return (dir);
}

char	*ft_check_link(char *str)
{
	int			f;
	char		*linkto;
	struct stat	buff;

	linkto = ft_strnew(256);
	f = readlink(str, linkto, 255);
	if (f > 0)
	{
		linkto[f] = '\0';
	}
	stat(str, &buff);
	if (S_ISDIR(buff.st_mode))
		return (linkto);
	ft_strdel(&linkto);
	return (NULL);
}
