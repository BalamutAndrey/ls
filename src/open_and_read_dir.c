/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_read_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:42:40 by geliz             #+#    #+#             */
/*   Updated: 2020/01/27 17:10:11 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_is_it_prev_cur_dir(t_keylist *kl)
{
	if (ft_strlen(kl->fin_current->name) == 1
				&& kl->fin_current->name[0] == '.')
		kl->fin_current->type = 2;
	if (ft_strlen(kl->fin_current->name) == 2 &&
			kl->fin_current->name[0] == '.' && kl->fin_current->name[1] == '.')
	{
		kl->fin_current->type = 2;
	}
	if (kl->fin_current->name[0] == '.')
		kl->fin_current->type = 2; /*hidden files*/
}

int		ft_read_dir_cycle(t_keylist *kl, DIR *dir)
{
	struct dirent	*entry;
	struct stat		buff;
	char			*t;
	int				err;

	while ((entry = readdir(dir)) != NULL)
	{
		if (kl->fin_current->name)
			kl->fin_current = ft_create_next_t_fin(kl, kl->fin_current->dir);
		t = ft_strjoin_arg("%s %s %s", kl->fin_first->dir, "/", entry->d_name);
		err = entry->d_type == DT_LNK ? lstat(t, &buff) : stat(t, &buff);
		if (err != 0)
			return (-1);
		if (entry->d_namlen > 0)
			kl->fin_current->name = ft_strdup(entry->d_name);
		kl->fin_current->type = buff.st_mode & S_IFDIR ? 1 : 0;
		if (ft_file_info(kl, buff, listxattr(t, NULL, 0, 0)) != 1)
			return (-1);
		ft_is_it_prev_cur_dir(kl);
		ft_strdel(&t);
	}
	return (0);
}

int		ft_open_and_read_dir(t_keylist *kl, char *cur)
{
	DIR		*dir;

	if (cur == NULL)
		return (0);
	kl->fin_first = ft_create_next_t_fin(kl, cur);
	kl->fin_current = kl->fin_first;
	dir = opendir(cur);
	if (ft_read_dir_cycle(kl, dir) == -1)
		return (0);
	//ft_sort_t_fin(&first, (*ft_alphabet_sort));
	ft_print_dir(kl);
	ft_recursive_call(kl);
	ft_delete_lists(kl);
	closedir(dir);
	return (0);
}
