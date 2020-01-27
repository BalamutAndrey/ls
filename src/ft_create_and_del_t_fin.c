/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_del_t_fin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:14:17 by geliz             #+#    #+#             */
/*   Updated: 2020/01/27 17:02:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_delete_lists(t_keylist *kl)
{
	char	*tmp;
	t_fin	*temp;
	
	while (kl->fin_first != NULL)
	{
		if ((tmp = kl->fin_first->dir) != NULL)
			ft_strdel(&tmp);
		if ((tmp = kl->fin_first->name) != NULL)
			ft_strdel(&tmp);
		temp = kl->fin_first->next;
		kl->fin_first->next = NULL;
		kl->fin_first->type = 0;
		free(kl->fin_first);
		kl->fin_first = temp;
	}
}

t_fin	*ft_create_next_t_fin(t_keylist *kl, char *dir)
{
	t_fin			*new;

	new = malloc(sizeof(t_fin));/*здесь может быть ft_memalloc*/
	new->dir = ft_strdup(dir);
	new->name = NULL;
	new->type = -1;
	new->next = NULL;
	new->info = NULL;
	if (kl->fin_current)
		kl->fin_current->next = new;
	return (new);
	
}
