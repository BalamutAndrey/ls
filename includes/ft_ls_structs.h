/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:49:59 by eboris            #+#    #+#             */
/*   Updated: 2020/02/07 13:16:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCTS_H
# define FT_LS_STRUCTS_H

typedef struct				s_dirkeylist
{
	char					*dir;
	struct s_dirkeylist		*next;
}							t_dirkeylist;

typedef struct				s_printcols
{
	int						term_width;
	int						file_quanity;
	int						file_maxlen;
	int						file_rows;
	int						file_cols;
	int						printed;
	int						cur_pos;
	int						next_pos;
	int						new_row;
	int						tabs;
}							t_printcols;

typedef	struct				s_fileinfo
{
	int						blocks;
	char					*chmod;
	int						type;
	char					*login;
	char					*group;
	uint64_t				size;
	char					*time;
	time_t					mtime;
	time_t						atime;
}							t_fileinfo;

typedef	struct				s_fin
{
	char					*name;
	char					*linkto;
	char					*dir;
	int						type;
	t_fileinfo				*info;
	struct s_fin			*next;
}							t_fin;

typedef	struct				s_maxsize
{
	int						type;
	int						login;
	int						group;
	int						size;
	int64_t					name;
	int						col;
	int						row;
	int						total;
	int						totalfile;
}							t_maxsize;

typedef struct				s_keylist
{
	char					*programm_name;
	int						l;
	int						r_big;
	int						a;
	int						r;
	int						t;
	int						u;
	int						f;
	int						g;
	int						x;
	int						a_big;
	int						l_big;
	int						o;
	int						s_big;
	int						g_big;
	int						one;
	int						c_big;
	t_dirkeylist			*first;
	t_dirkeylist			*current;
	t_dirkeylist			*end;
	int						*isfile;
	t_fin					*t_first;
	int						dirnbr;
	t_maxsize				*maxsize;
}							t_keylist;

#endif
