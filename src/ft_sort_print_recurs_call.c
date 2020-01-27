/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_print_recurs_call.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:23:03 by geliz             #+#    #+#             */
/*   Updated: 2020/01/27 17:23:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive_call(t_keylist *kl)
{
	kl->fin_current = kl->fin_first;
	while (kl->fin_current != NULL)
	{
		if (kl->fin_current->type == 1)
		{
			kl->fin_current->dir = ft_strjoin_arg("%f %s %s",
				kl->fin_first->dir, "/", kl->fin_current->name);
			ft_open_and_read_dir(kl, kl->fin_current->dir);
		}
		if (!kl->fin_current)
			kl->fin_current = NULL;
		else
			kl->fin_current = kl->fin_current->next;
	}
//	ft_delete_lists(temp);
}

void	ft_print_dir(t_keylist *kl)
{
	size_t	len;

	ft_printf("\n./%s\n", kl->fin_first->dir);
	len = 0;
	kl->fin_current = kl->fin_first;
	while (kl->fin_current->next != NULL)
	{
		if (ft_strlen(kl->fin_current->name) > len)
			len = ft_strlen(kl->fin_current->name);
		kl->fin_current = kl->fin_current->next;
	}
	while (len % 8 != 0)
		len++;
	kl->fin_current = kl->fin_first;
	while (kl->fin_current != NULL)
	{
		if (kl->fin_current->type != 2)
		{
			ft_printf("%s %-*s\n", kl->fin_current->info->chmod, len,
						kl->fin_current->name);
		}
		kl->fin_current = kl->fin_current->next;
	}
	printf("\n");
}

void	ft_split_t_fin(t_fin *first, t_fin **a, t_fin **b)
{
	t_fin	*left;
	t_fin	*right;

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

t_fin	*ft_merge(t_fin *a, t_fin *b, int (*cmp)())
{
	t_fin	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (cmp(a, b) < 0)
	{
		result = a;
		result->next = ft_merge(a->next, b, (*cmp));
	}
	else
	{
		result = b;
		result->next = ft_merge(a, b->next, (*cmp));
	}
	return (result);
}

void	ft_sort_t_fin(t_fin **list, int (*cmp)())
{
	t_fin	*first;
	t_fin	*a;
	t_fin	*b;

	first = *list;
	if (first && first->next)
	{
		ft_split_t_fin(first, &a, &b);
		ft_sort_t_fin(&a, (*cmp));
		ft_sort_t_fin(&b, (*cmp));
		*list = ft_merge(a, b, (*cmp));
	}
}
