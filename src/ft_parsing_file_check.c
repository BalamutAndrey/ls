/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:29:49 by eboris            #+#    #+#             */
/*   Updated: 2020/02/01 16:58:24 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_create_tempdir(t_keylist *kl, char *filename)
{
	t_fin	*temp;
	char	*fn;

	fn = ft_strdup(filename);
	if (kl->t_first == NULL)
	{
		temp = ft_create_next_t_fin(kl, NULL, fn);
		kl->t_first = temp;
	}
	else
	{
		temp = kl->t_first;
		while (temp->next != NULL)
			temp = temp->next;
		temp = ft_create_next_t_fin(kl, temp, fn);
	}
	temp->name = ft_strdup(temp->dir);
	if (kl->l_big == 0)
		ft_check_file_link(temp, fn);
	ft_read_dir_cycle_write(kl, temp, NULL, fn);
	return (0);
}

void	ft_check_file_link(t_fin *first, char *fn)
{
	struct stat		buff;
	char			*linkto;
	int				err;

	err = lstat(fn, &buff);
	if (S_ISLNK(buff.st_mode))
	{
		linkto = malloc(257 * sizeof(char));
		linkto[256] = '\0';
		if (err == 0)
		{
			err = readlink(fn, linkto, 255);
			if (err > 0)
				first->linkto = ft_strdup(linkto);
		}
	}
}
