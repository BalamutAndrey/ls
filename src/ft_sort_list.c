/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:05:20 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 18:47:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_alphabet_sort(t_fin *a, t_fin *b)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	return (res);
}

int		ft_size_sort(t_fin *a, t_fin *b)
{
	t_fileinfo	*a_in;
	t_fileinfo	*b_in;

	a_in = a->info;
	b_in = b->info;
	if (a_in->size < b_in->size)
		return (1);
	if (a_in->size == b_in->size)
		return (0);
	else
		return (-1);
}

int		ft_time_access_sort(t_fin *a, t_fin *b)
{
	(void)a;
	(void)b;
	return (0);
}

int		ft_time_mod_sort(t_fin *a, t_fin *b)
{
	int		res;
	(void)a;
	(void)b;

	res = 0;
	return (res);
}

void	ft_sort_list(t_keylist *kl, t_fin **list)
{
	if (kl->r == 0)
	{
		if (kl->t == 1)
			ft_sort_t_fin(kl, list, (*ft_time_mod_sort));
		else if (kl->u == 1)
			ft_sort_t_fin(kl, list, (*ft_time_access_sort));
		else if (kl->s_big == 1)
			ft_sort_t_fin(kl, list, (*ft_size_sort));
		else if (kl->f == 0)
			ft_sort_t_fin(kl, list, (*ft_alphabet_sort));
	}
	else
	{
		if (kl->t == 1)
			ft_sort_t_fin(kl, list, (*ft_time_mod_rev_sort));
		else if (kl->u == 1)
			ft_sort_t_fin(kl, list, (*ft_time_access_rev_sort));
		else if (kl->s_big == 1)
			ft_sort_t_fin(kl, list, (*ft_size_rev_sort));
		else if (kl->f == 0)
			ft_sort_t_fin(kl, list, (*ft_alphabet_rev_sort));
	}
}
