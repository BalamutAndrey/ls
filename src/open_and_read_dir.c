/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_read_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:42:40 by geliz             #+#    #+#             */
/*   Updated: 2020/01/22 18:24:21 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_is_it_prev_cur_dir(t_fin *temp)
{
	if (ft_strlen(temp->name) == 1 && temp->name[0] == '.')
		temp->type = 2;
	if (ft_strlen(temp->name) == 2 && temp->name[0] == '.' && temp->name[1] == '.')
		temp->type = 2;
	if (temp->name[0] == '.')
		temp->type = 2;/*hidden files*/
}

int		ft_read_dir_cycle(DIR *dir, t_fin *first)
{
	struct dirent	*entry;
	struct stat		buff;
	char			*t;
	int				err;

	while ((entry = readdir(dir)) != NULL)
	{
		t = ft_strjoin_arg("%s %s %s", first->dir, "/", entry->d_name);
		err = entry->d_type == DT_LNK ? lstat(t, &buff) : stat(t, &buff);
		if (err != 0)
			return (-1);
		if (entry->d_namlen > 0)
			first->name = ft_strdup(entry->d_name);
		first->type = buff.st_mode & S_IFDIR ? 1 : 0;
		first->chmod = ft_check_access_rights(buff);
		ft_is_it_prev_cur_dir(first);
		first->next = ft_create_next_t_fin(first);
		first = first->next;
		ft_strdel(&t);
	}
	return (0);
}

int		ft_open_and_read_dir(char *cur)
{
	DIR				*dir;
	t_fin			*first;

	if (cur == NULL)
		return (0);
	first = malloc(sizeof(t_fin));
	first->dir = ft_strdup(cur);
	dir = opendir(cur);
	if (ft_read_dir_cycle(dir, first) == -1)
		return (0);
	ft_sort_t_fin(first);
	ft_print_dir(first);
	ft_recursive_call(first);
	ft_delete_lists(first);
	closedir(dir);
	return (0);
}
