/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:00:20 by geliz             #+#    #+#             */
/*   Updated: 2020/01/29 16:49:11 by eboris           ###   ########.fr       */
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
	temp->info->chmod = ft_check_access_rights(buff, xattr);
	temp->info->type = ft_check_nlink(kl->maxsize, buff);
	temp->info->login = ft_check_login(kl->maxsize, buff);
	temp->info->group = ft_check_group(kl->maxsize, buff);
	temp->info->size = ft_check_size(kl->maxsize, buff);
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
	new->datacreate = NULL;
	new->timecreate = NULL;
	new->dataaccess = NULL;
	new->timeaccess = NULL;
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
	return (new);
}
