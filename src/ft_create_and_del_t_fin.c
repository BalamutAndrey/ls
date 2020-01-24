/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_del_t_fin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:14:17 by geliz             #+#    #+#             */
/*   Updated: 2020/01/24 20:16:57 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_delete_lists(t_fin *first)
{
	t_fin	*temp;
	
	while (first != NULL)
	{
		if (first->dir)
			ft_strdel(&first->dir);
		if (first->name)
			ft_strdel(&first->name);
		if (first->chmod)
			ft_strdel(&first->chmod);
		temp = first->next;
		first->next = NULL;
		first->type = 0;
		free(first);
		first = temp;
	}
}

t_fin	*ft_create_next_t_fin(t_fin *temp, char *dir)
{
	t_fin			*new;

	new = malloc(sizeof(t_fin));/*здесь может быть ft_memalloc*/
	new->dir = ft_strdup(dir);
	new->name = NULL;
	new->type = -1;
	new->next = NULL;
	new->chmod = NULL;
	if (temp)
		temp->next = new;
	return (new);
}
