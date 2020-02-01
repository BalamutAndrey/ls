/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printiing_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:37:55 by eboris            #+#    #+#             */
/*   Updated: 2020/02/01 20:17:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "temp.h"

int		ft_printing_x(t_keylist *kl, t_fin *temp, int64_t *l)
{
	int	i;

	i = ft_ioctl();
	if (((kl->maxsize->name) * (*l + 1)) >= i)
	{
		ft_printf("\n");
		*l = 0;
	}
	ft_printf("%-*s", kl->maxsize->name, temp->name);
	return (1);
}

void	ft_fill_in(t_printcols *in, t_fin *first)
{
	int		i;
	int		len;
	t_fin	*temp;

	in->term_width = ft_ioctl();
	in->file_quanity = 0;
	in->file_maxlen = 0;
	temp = first;
	while (temp)
	{
		len = ft_strlen(temp->name);
		if (len > in->file_maxlen)
			in->file_maxlen = len;
		in->file_quanity++;
		temp = temp->next;
	}
	while (in->file_maxlen % 8 != 0)
		in->file_maxlen++;
	if (in->file_maxlen > in->term_width)
	{
		in->file_cols = 1;
		in->file_rows = in->file_quanity;
	}
	else
	{

		i = in->file_maxlen * in->file_quanity;
		in->file_cols = in->term_width / in->file_maxlen;
		in->file_rows = in->file_quanity / in->file_cols;
		if (in->file_quanity % in->file_cols > 0)
			in->file_rows++;
	}
}

int		ft_printing_c(t_keylist *kl, t_fin *first)
{
	t_printcols	in;
	t_fin		*temp;
	int			printed;
	int			cur_pos;
	int			next_pos;
	int			new_row;
	int			tabs;

	ft_fill_in(&in, first);
	printed = 0;
	cur_pos = 0;
	next_pos = 0;
	new_row = 0;
	temp = first;
	while (printed < in.file_quanity)
	{
		if (cur_pos == next_pos)
		{
			tabs = (in.file_maxlen - ft_strlen(temp->name)) / 8;
			if ((in.file_maxlen - ft_strlen(temp->name)) % 8 > 0)
				tabs++;
			ft_printf("%-s", temp->name);
			while (tabs-- > 0)
				write(1, "\t", 1);
			printed++;
			next_pos += in.file_rows;
			if (next_pos >= in.file_quanity)
			{
				if (printed != in.file_quanity)
					ft_printf("\n");
				++new_row;
				next_pos = new_row;
				cur_pos = 0;
				temp = first;
			}
		}
		cur_pos++;
		temp = temp->next;
	}
	(void)kl;
	return (1);
}
