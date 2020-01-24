/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:44:15 by geliz             #+#    #+#             */
/*   Updated: 2020/01/24 20:24:26 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>

typedef	struct	s_fin
{
	char	*name;
	char	*dir;
	int		type;
	char	*chmod;
	struct s_fin	*next;
}				t_fin;

int		ft_open_and_read_dir(char *cur);
int		ft_read_dir_cycle(DIR *dir, t_fin *first);
void	ft_is_it_prev_cur_dir(t_fin *temp);
t_fin	*ft_create_next_t_fin(t_fin *temp, char *dir);

void	ft_sort_t_fin(t_fin **list, int (*cmp)());
void	ft_print_dir(t_fin *first);
void	ft_recursive_call(t_fin *first);

void	ft_delete_lists(t_fin *first);

char	*ft_check_access_rights(struct stat buff);
int		ft_file_info(struct stat buff, t_fin *first);
int		ft_alphabet_sort(t_fin *a, t_fin *b);

#endif