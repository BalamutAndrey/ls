/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:44:15 by geliz             #+#    #+#             */
/*   Updated: 2020/02/13 16:51:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdint.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_ls_structs.h"

/*
** ft_ls.c
*/
int				main(int argc, char **argv);
/*
** ft_keylist.c
*/
t_keylist		*create_keylist(void);
void			create_keylist_1(t_keylist *kl);
t_dirkeylist	*create_dirkeylist(void);
t_dirkeylist	*add_dkl(t_keylist *kl);
void			remove_list(t_keylist *kl);
/*
** ft_parsing.c
*/
t_keylist		*ft_ls_parsing_key(int argc, char **argv);
t_keylist	    *ft_parsing_dir(t_keylist *kl, int argc, char **argv, int i);
int				ft_ls_writedir(t_keylist *kl, char *argv);
DIR				*ft_ls_writedir_open(t_keylist *kl, char *argv);
int				ft_ls_key(t_keylist *kl, char *argv);
/*
** ft_parsing_key.c
*/
int				ft_ls_key_if_1(t_keylist *kl, char k);
int				ft_ls_key_if_2(t_keylist *kl, char k);
int 			ft_ls_key_if_3(t_keylist *kl, char k);
int 			ft_ls_key_if_4(t_keylist *kl, char k);
/*
** ft_parsing_file_check.c
*/
int	            ft_create_tempdir(t_keylist *kl, char *filename);
void	        ft_check_file_link(t_fin *first, char *fn);
/*
** ft_open_and_read_dir.c
*/
int				ft_open_and_read_dir(t_keylist *kl, char *cur);
int				ft_read_dir_cycle(t_keylist *kl, DIR *dir, t_fin *first);
int     		ft_read_dir_cycle_write(t_keylist *kl, t_fin *first,
								struct dirent *entry, char *t);
void			ft_is_it_prev_cur_dir(t_keylist *kl, t_fin *temp);
int		        ft_dir_sort_print(t_keylist *kl, t_fin *first);
/*
** ft_read_stat.c
*/
int             ft_read_dir_cycle_lstat(t_fin *first, struct stat *buff,
                                        char *t);
int             ft_read_dir_cycle_stat(struct stat *buff, char *t);
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
void		    ft_del_fileinfo(t_fileinfo *temp);
t_maxsize		*ft_create_maxsize(void);
void	    	ft_reset_maxsize(t_maxsize *new);
/*
** ft_sort_list.c
*/
int				ft_alphabet_sort(t_fin *a, t_fin *b);
int		        ft_time_mod_sort(t_fin *a, t_fin *b);
int	        	ft_time_access_sort(t_fin *a, t_fin *b);
int     		ft_size_sort(t_fin *a, t_fin *b);
void            ft_sort_list(t_keylist *kl, t_fin **list);
/*
** ft_sort_list_reverse.c
*/
int	        	ft_time_access_rev_sort(t_fin *a, t_fin *b);
int	        	ft_size_rev_sort(t_fin *a, t_fin *b);
int		        ft_alphabet_rev_sort(t_fin *a, t_fin *b);
int		        ft_time_mod_rev_sort(t_fin *a, t_fin *b);
/*
** ft_check_access_rights.c
*/
void			ft_is_it_dir_file_link(char *str, struct stat buff);
char			*ft_check_access_rights(struct stat buff, int xattr);
char			*ft_check_access_ext_rights(struct stat buff, int xattr, char *str);
int				ft_check_nlink(t_maxsize *maxsize, struct stat buff);
/*
** t_check_login_group_size.c
*/
char			*ft_check_login(t_maxsize *maxsize, struct stat buff);
char			*ft_check_group(t_maxsize *maxsize, struct stat buff);
uint64_t	    ft_check_size(t_maxsize *maxsize, struct stat buff);
/*
** ft_sort_print_recurs_call.c
*/
void			ft_recursive_call(t_keylist *kl, t_fin *first);
void			ft_print_dir(t_keylist *kl, t_fin *firsts);
void			ft_split_t_fin(t_fin *first, t_fin **a, t_fin **b);
t_fin			*ft_merge(t_fin *a, t_fin *b, int (*cmp)());
void			ft_sort_t_fin(t_keylist *kl, t_fin **list, int (*cmp)());
/*
** ft_sort_arg_dir.c
*/
void			ft_sort_arg_dirs(t_keylist *kl);
/*
** ft_printing.c
*/
void			ft_printing(t_keylist *kl, t_fin *temp);
int64_t     	ft_printing_while(t_keylist *kl, t_fin *temp, int64_t l);
int				ft_printing_1(t_keylist *kl, t_fin *temp);
int				ft_printing_l(t_keylist *kl, t_fin *temp);
int				ft_printing_x(t_keylist *kl, t_fin *temp, int64_t *l);
/*
** ft_ioctl.c
*/
int             ft_ioctl(void);
/*
** ft_printiing_col.c
*/
void        	ft_fill_in(t_printcols *in, t_fin *first);
void        	ft_fill_in_check(t_printcols *in);
int				ft_printing_c(t_keylist *kl, t_fin *temp);
t_fin           *ft_printing_c_while(t_fin *first, t_fin *temp,
                                        t_printcols *in);
t_printcols	    *ft_printing_col_in(void);
/*
** ft_check_date_time.c
*/
int	            ft_time_six_months(int t, char *src, char *str);
int				ft_time_10000(char *src, char *str);
char	        *ft_time_pars(char *src, int t);
/*
** ft_print_error.c
*/
void	        ft_print_error(t_keylist *kl, char	*cur);
void	        ft_print_illegal_option(char *filename, char c);
/*
**  ft_print_c_check_a_a_big.c
*/
t_fin	        *ft_check_keys_a_a_big(t_fin *first, t_keylist *kl);
#endif
