/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arg_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:45:54 by geliz             #+#    #+#             */
/*   Updated: 2020/02/13 18:07:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dirkeylist_alphabet_rev_sort(t_dirkeylist *a, t_dirkeylist *b)
{
	int		res;

	res = ft_strcmp(a->dir, b->dir);
	res = res * -1;
	return (res);
}

int		ft_dirkeylist_alphabet_sort(t_dirkeylist *a, t_dirkeylist *b)
{
	int		res;

	res = ft_strcmp(a->dir, b->dir);
	return (res);
}

void	ft_sort_arg_dirs(t_keylist *kl)
{
	t_dirkeylist	*first;

	first = kl->first;
	if (kl->r == 1)
		ft_sort_dirkeylist(&first, (*ft_dirkeylist_alphabet_rev_sort));
	else
		ft_sort_dirkeylist(&first, (*ft_dirkeylist_alphabet_sort));
	kl->first = first;
}
