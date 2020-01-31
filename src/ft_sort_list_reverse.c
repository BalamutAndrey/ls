/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:12:43 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 18:47:28 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_alphabet_rev_sort(t_fin *a, t_fin *b)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	res = res * -1;
	return (res);
}

int		ft_size_rev_sort(t_fin *a, t_fin *b)
{
	t_fileinfo	*a_in;
	t_fileinfo	*b_in;

	a_in = a->info;
	b_in = b->info;
	if (a_in->size > b_in->size)
		return (1);
	if (a_in->size == b_in->size)
		return (0);
	else
		return (-1);
}

int		ft_time_access_rev_sort(t_fin *a, t_fin *b)
{
	(void)a;
	(void)b;
	return (0);
}

int		ft_time_mod_rev_sort(t_fin *a, t_fin *b)
{
	(void)a;
	(void)b;
	return (0);
}
