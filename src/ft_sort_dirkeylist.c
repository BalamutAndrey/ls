/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dirkeylist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:06:58 by geliz             #+#    #+#             */
/*   Updated: 2020/02/15 14:18:53 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_split_t_dirkeylist(t_dirkeylist *first, t_dirkeylist **a,
			t_dirkeylist **b)
{
	t_dirkeylist	*left;
	t_dirkeylist	*right;

	left = first;
	right = first->next;
	while (right)
	{
		right = right->next;
		if (right)
		{
			left = left->next;
			right = right->next;
		}
	}
	right = left->next;
	left->next = NULL;
	left = first;
	*a = left;
	*b = right;
}

t_dirkeylist	*ft_merge_dirkeylist(t_dirkeylist *a, t_dirkeylist *b,
					int (*cmp)())
{
	t_dirkeylist	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (cmp(a, b) < 0)
	{
		result = a;
		result->next = ft_merge_dirkeylist(a->next, b, (*cmp));
	}
	else
	{
		result = b;
		result->next = ft_merge_dirkeylist(a, b->next, (*cmp));
	}
	return (result);
}

void			ft_sort_dirkeylist(t_dirkeylist **list, int (*cmp)())
{
	t_dirkeylist	*first;
	t_dirkeylist	*a;
	t_dirkeylist	*b;

	first = *list;
	if (first && first->next)
	{
		ft_split_t_dirkeylist(first, &a, &b);
		ft_sort_dirkeylist(&a, (*cmp));
		ft_sort_dirkeylist(&b, (*cmp));
		*list = ft_merge_dirkeylist(a, b, (*cmp));
	}
}
