/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:12:43 by eboris            #+#    #+#             */
/*   Updated: 2020/02/16 17:54:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_read_dir_cycle_lstat(t_fin *first, struct stat *buff, char *t)
{
	int		err;
	char	*linkto;

	err = lstat(t, buff);
	linkto = malloc(257 * sizeof(char));
	linkto[256] = '\0';
	if (err == 0)
	{
		err = readlink(t, linkto, 255);
		if (err > 0)
		{
			linkto[err] = '\0';
			if (first->linkto)
				ft_strdel(&first->linkto);
			first->linkto = ft_strdup(linkto);
			ft_strdel(&linkto);
		}
		err = 0;
	}
	return (err);
}

int		ft_read_dir_cycle_stat(struct stat *buff, char *t)
{
	int	err;

	err = stat(t, buff);
	return (err);
}
