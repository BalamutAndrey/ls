/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:37:55 by eboris            #+#    #+#             */
/*   Updated: 2020/02/07 15:23:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_in(t_printcols *in, t_fin *first, t_keylist *kl)
{
	int		len;
	t_fin	*temp;

	if (!kl)
		len = 0;
	in->term_width = ft_ioctl();
	in->file_quanity = 0;
	in->file_maxlen = 0;
	temp = first;
	while (temp)
	{
		len = ft_strlen(temp->name);
		if (len > in->file_maxlen)
			in->file_maxlen = len + 1;
		in->file_quanity++;
		temp = temp->next;
	}
	while (in->file_maxlen % 8 != 0)
		in->file_maxlen++;
	ft_fill_in_check(in);
}

void	ft_fill_in_check(t_printcols *in)
{
	if (in->file_maxlen > in->term_width)
	{
		in->file_cols = 1;
		in->file_rows = in->file_quanity;
	}
	else
	{
		if (in->file_maxlen != 0)
			in->file_cols = in->term_width / in->file_maxlen;
		else
			in->file_cols = 1;
		if (in->file_cols)
			in->file_rows = in->file_quanity / in->file_cols;
		else
			in->file_rows = 0;
		if (in->file_quanity % in->file_cols > 0)
			in->file_rows++;
	}
}

int		ft_printing_c(t_keylist *kl, t_fin *first)
{
	t_printcols	*in;
	t_fin		*temp;

	if ((in = ft_printing_col_in()) == NULL)
		return (0);
	ft_fill_in(in, first, kl);
	temp = first;
	while (in->printed < in->file_quanity)
	{
		temp = ft_printing_c_while(first, temp, in);
		in->cur_pos += 1;
		temp = temp->next;
	}
	free(in);
	(void)kl;
	return (1);
}

t_fin	*ft_printing_c_while(t_fin *first, t_fin *temp, t_printcols *in)
{
	if (in->cur_pos == in->next_pos)
	{
		in->tabs = (in->file_maxlen - ft_strlen(temp->name)) / 8;
		if ((in->file_maxlen - ft_strlen(temp->name)) % 8 > 0)
			in->tabs += 1;
		ft_printf("%-s", temp->name);
		in->tabs += 1;
		while ((in->tabs -= 1) > 0)
			write(1, "\t", 1);
		in->printed++;
		in->next_pos += in->file_rows;
		if (in->next_pos >= in->file_quanity)
		{
			if (in->printed != in->file_quanity)
				ft_printf("\n");
			in->new_row += 1;
			in->next_pos = in->new_row;
			in->cur_pos = 0;
			temp = first;
		}
	}
	return (temp);
}

t_printcols	*ft_printing_col_in(void)
{
	t_printcols	*in;

	if ((in = malloc(sizeof(t_printcols))) == NULL)
		return (NULL);
	in->term_width = 0;
	in->file_quanity = 0;
	in->file_maxlen = 0;
	in->file_rows = 0;
	in->file_cols = 0;
	in->printed = 0;
	in->cur_pos = 0;
	in->next_pos = 0;
	in->new_row = 0;
	in->tabs = 0;
	return (in);
}
