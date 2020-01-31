/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:00:20 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 18:13:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_file_info(t_keylist *kl, struct stat buff,
							t_fin *temp, int xattr)
{
	if ((temp->info = ft_create_fileinfo()) == NULL)
		return (0);
	if (kl->maxsize == NULL)
	{
		if ((kl->maxsize = ft_create_maxsize()) == NULL)
			return (0);
	}
	if (kl->u == 1)
		temp->info->time = ft_time_pars(ctime(&buff.st_atime), buff.st_atime);
	else
		temp->info->time = ft_time_pars(ctime(&buff.st_mtime), buff.st_mtime);
	if ((temp->type < 2) || (kl->a > 0) ||
		((kl->a_big > 0) && (temp->type == 3)))
	{
		temp->info->chmod = ft_check_access_rights(buff, xattr);
		temp->info->type = ft_check_nlink(kl->maxsize, buff);
		temp->info->login = ft_check_login(kl->maxsize, buff);
		temp->info->group = ft_check_group(kl->maxsize, buff);
		temp->info->size = ft_check_size(kl->maxsize, buff);
		kl->maxsize->total = kl->maxsize->total + buff.st_blocks;
		temp->info->mtime = buff.st_mtime;
		temp->info->atime = buff.st_atime;
	}
	return (1);
}

t_fileinfo	*ft_create_fileinfo(void)
{
	t_fileinfo	*new;

	new = malloc(sizeof(t_fileinfo));
	if (!new)
		return (NULL);
	new->blocks = 0;
	new->chmod = NULL;
	new->type = 0;
	new->login = NULL;
	new->group = NULL;
	new->size = 0;
	new->time = NULL;
	new->mtime = 0;
	new->atime = 0;
	return (new);
}

t_maxsize	*ft_create_maxsize(void)
{
	t_maxsize	*new;

	new = malloc(sizeof(t_maxsize));
	if (!new)
		return (NULL);
	new->type = 0;
	new->login = 0;
	new->group = 0;
	new->size = 0;
	new->name = 0;
	new->total = 0;
	new->col = 0;
	new->row = 0;
	new->totalfile = 0;
	return (new);
}
