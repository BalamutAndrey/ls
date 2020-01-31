/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:05:20 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 17:31:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_alphabet_sort(t_fin *a, t_fin *b)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	return (res);
}

void	ft_sort_list(t_keylist *kl, t_fin **list)
{
	
	ft_sort_t_fin(kl, list, (*ft_alphabet_sort));
}