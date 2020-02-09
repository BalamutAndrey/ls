/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:21:42 by eboris            #+#    #+#             */
/*   Updated: 2020/02/09 14:40:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_keylist	*kl;
	int			i;

	if (!(kl = ft_ls_parsing_key(argc, argv)))
	{
		return (0);
	}
	i = 0;
	kl->current = kl->first;
	while (++i <= kl->dirnbr)
	{
		ft_open_and_read_dir(kl, kl->current->dir);
		kl->current = kl->current->next;
		if ((i + 1) <= kl->dirnbr)
			ft_printf("\n");
	}
	remove_list(kl);
	return (0);
}
