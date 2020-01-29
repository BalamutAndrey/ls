/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:44:15 by geliz             #+#    #+#             */
/*   Updated: 2020/01/29 15:05:09 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/xattr.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_ls_structs.h"

/*
** ft_ls.c
*/
int				main(int argc, char **argv);
/*
** keylist.c
*/
t_keylist		*create_keylist(void);
void			create_keylist_1(t_keylist *kl);
t_dirkeylist	*create_dirkeylist(void);
t_dirkeylist	*add_dkl(t_keylist *kl);
void			remove_list(t_keylist *kl);
/*
** parsing.c
*/
t_keylist		*ft_ls_parsing_key(int argc, char **argv);
void			ft_ls_writedir(t_keylist *kl, char *argv);
int				ft_ls_key(t_keylist *kl, char *argv);
int				ft_ls_key_if_1(t_keylist *kl, char k);
int				ft_ls_key_if_2(t_keylist *kl, char k);
/*
** open_and_read_dir.c
*/
int				ft_open_and_read_dir(t_keylist *kl, char *cur);
int				ft_read_dir_cycle(t_keylist *kl, DIR *dir, t_fin *first);
void			ft_is_it_prev_cur_dir(t_keylist *kl, t_fin *temp);
/*
** ft_create_and_del_t_fin.c
*/
void			ft_delete_lists(t_keylist *kl, t_fin *first);
t_fin			*ft_create_next_t_fin(t_keylist *kl, t_fin *temp, char *dir);
/*
** ft_file_info.c
*/
int				ft_file_info(t_keylist *kl, struct stat buff, 
                                t_fin *temp, int xattr);
t_fileinfo		*ft_create_fileinfo(void);
t_maxsize		*ft_create_maxsize(void);
/*
** ft_sort_list.c
*/
int				ft_alphabet_sort(t_fin *a, t_fin *b);
/*
** ft_check_access_rights.c
*/
char			*ft_check_access_rights(struct stat buff, int xattr);
void			ft_is_it_dir_file_link(char *str, struct stat buff);
/*
** ft_sort_print_recurs_call.c
*/
void			ft_recursive_call(t_keylist *kl, t_fin *first);
void			ft_print_dir(t_keylist *kl, t_fin *firsts);
void			ft_split_t_fin(t_fin *first, t_fin **a, t_fin **b);
t_fin			*ft_merge(t_fin *a, t_fin *b, int (*cmp)());
void			ft_sort_t_fin(t_keylist *kl, t_fin **list, int (*cmp)());

#endif
