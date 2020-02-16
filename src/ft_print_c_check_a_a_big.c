/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_check_a_a_big.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:56:27 by geliz             #+#    #+#             */
/*   Updated: 2020/02/16 17:13:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fin	*create_next_temp_t_fin(t_fin *source, t_fin *prev)
{
	t_fin	*cur;

	cur = malloc(sizeof(t_fin));
	cur->dir = ft_strdup(source->dir);
	cur->name = ft_strdup(source->name);
	cur->info = NULL;
	cur->linkto = NULL;
	cur->type = 0;
	cur->info = NULL;
	cur->next = NULL;
	if (prev)
		prev->next = cur;
	return (cur);
}

t_fin	*ft_check_keys_a_a_big(t_fin *first, t_keylist *kl)
{
	t_fin	*res;
	t_fin	*temp;

	if (kl->a == 1)
		return (NULL);
	res = NULL;
	temp = NULL;
	while (first)
	{
		if (first->type == 2)
			first = first->next;
		else if (kl->a_big == 0 && first->type == 3)
			first = first->next;
		else
		{
			temp = create_next_temp_t_fin(first, temp);
			if (!res)
				res = temp;
			first = first->next;
		}
	}
	return (res);
}
