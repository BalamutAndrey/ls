/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_del_t_fin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:14:17 by geliz             #+#    #+#             */
/*   Updated: 2020/01/29 15:00:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_delete_lists(t_keylist *kl, t_fin *first)
{
	t_fin	*temp;
	
	while (first != NULL)
	{
		if (first->dir)
			ft_strdel(&first->dir);
		if (first->name)
			ft_strdel(&first->name);
		temp = first->next;
		first->next = NULL;
		first->type = 0;
		free(first);
		first = temp;
	}
	(void)kl; //not used
}

t_fin	*ft_create_next_t_fin(t_keylist *kl, t_fin *temp, char *dir)
{
	t_fin			*new;

	new = malloc(sizeof(t_fin));/*здесь может быть ft_memalloc*/
	new->dir = ft_strdup(dir);
	new->name = NULL;
	new->type = -1;
	new->next = NULL;
	new->info = NULL;
	if (temp)
		temp->next = new;
	return (new);
	(void)kl; //not used
}
