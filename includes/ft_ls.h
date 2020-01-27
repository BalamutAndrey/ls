/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:44:15 by geliz             #+#    #+#             */
/*   Updated: 2020/01/27 13:45:51 by eboris           ###   ########.fr       */
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
int				ft_open_and_read_dir(char *cur);
int				ft_read_dir_cycle(DIR *dir, t_fin *first);
void			ft_is_it_prev_cur_dir(t_fin *temp);
/*
** ft_create_and_del_t_fin.c
*/
t_fin			*ft_create_next_t_fin(t_fin *temp, char *dir);
void			ft_delete_lists(t_fin *first);
/*
** ft_file_info.c
*/
int				ft_file_info(struct stat buff, t_fin *first, int xattr);
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
void			ft_recursive_call(t_fin *first);
void			ft_print_dir(t_fin *first);
void			ft_split_t_fin(t_fin *first, t_fin **a, t_fin **b);
t_fin			*ft_merge(t_fin *a, t_fin *b, int (*cmp)());
void			ft_sort_t_fin(t_fin **list, int (*cmp)());

#endif
