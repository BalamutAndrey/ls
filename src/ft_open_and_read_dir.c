/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_and_read_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:42:40 by geliz             #+#    #+#             */
/*   Updated: 2020/02/10 17:27:41 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_is_it_prev_cur_dir(t_keylist *kl, t_fin *temp)
{
	if (ft_strlen(temp->name) == 1 && temp->name[0] == '.')
		temp->type = 2;
	if (ft_strlen(temp->name) == 2 && temp->name[0] == '.'
			&& temp->name[1] == '.')
	{
		temp->type = 2;
	}
	if ((kl->a != 1) && (temp->type != 2) && (temp->name[0] == '.'))
		temp->type = 3; /*hidden files*/
	(void)kl; //not used
}

int		ft_read_dir_cycle(t_keylist *kl, DIR *dir, t_fin *first)
{
	struct dirent	*entry;
//	struct stat		buff;
	char			*t;

	while ((entry = readdir(dir)) != NULL)
	{
		if (first->name)
			first = ft_create_next_t_fin(kl, first, first->dir);
		t = ft_strjoin_arg("%s %s %s", first->dir, "/", entry->d_name);
//		ft_check_file_link(first, first->dir);
//		if ((first->linkto != NULL) && (kl->l > 0) && (kl->l_big < 1))
//		{
//			first->name = ft_strdup(first->dir);	
//			ft_read_dir_cycle_lstat(first, &buff, first->name);
//			if (ft_file_info(kl, buff, first, listxattr(first->name, NULL, 0, XATTR_NOFOLLOW)) != 1)
//				return (-1);
//			first->type = 7;
//			//ft_dir_sort_print(kl, first);
//			return (0);
//		}
//		else
		ft_read_dir_cycle_write(kl, first, entry, t);
	}
	return (0);
}

int		ft_read_dir_cycle_write(t_keylist *kl, t_fin *first,
								struct dirent *entry, char *t)
{
	struct stat		buff;
	int				err;

	if (((entry != NULL) && (entry->d_type == DT_LNK) && (kl->l_big == 0)) ||
		((first->linkto != NULL) && (kl->l_big == 0)))
		err = ft_read_dir_cycle_lstat(first, &buff, t);
	else
		err = ft_read_dir_cycle_stat(&buff, t);
	if (err != 0)
		return (-1);
	if ((entry != NULL) && (entry->d_namlen > 0))
		first->name = ft_strdup(entry->d_name);
	if (first->type < 1)
		first->type = buff.st_mode & S_IFDIR ? 1 : 0;
	ft_is_it_prev_cur_dir(kl, first);
	if ((S_ISSOCK(buff.st_mode)) || (S_ISBLK(buff.st_mode)) ||
			(S_ISCHR(buff.st_mode)))
	{
		if (first->type == 3)
			first->type = 6;
		else
			first->type = 5;
	}
	if (ft_file_info(kl, buff, first, listxattr(t, NULL, 0, XATTR_NOFOLLOW)) != 1)
		return (-1);
	ft_strdel(&t);
	return (0);
}

int		ft_open_and_read_dir(t_keylist *kl, char *cur)
{
	DIR		*dir;
	t_fin	*first;

	if (cur == NULL)
		return (0);
	first = ft_create_next_t_fin(kl, NULL, cur);
	dir = opendir(cur);
	if (dir == NULL)
	{
		ft_print_error(kl, cur);
		return (0);
	}
	if (ft_read_dir_cycle(kl, dir, first) == -1)
		return (0);
	if (ft_dir_sort_print(kl, first) != 0)
		return (0);
	closedir(dir);
	return (0);
}

int		ft_dir_sort_print(t_keylist *kl, t_fin *first)
{
	ft_sort_list(kl, &first);
	ft_print_dir(kl, first);
	ft_reset_maxsize(kl->maxsize);
	if (kl->r_big == 1)
		ft_recursive_call(kl, first);
	ft_delete_lists(kl, first);
	return (0);
}
