/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_print_recurs_call.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:23:03 by geliz             #+#    #+#             */
/*   Updated: 2020/02/01 17:14:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive_call(t_keylist *kl, t_fin *first)
{
	t_fin	*temp;

	temp = first;
	while (first != NULL)
	{
		if (first->type == 1)
		{
			first->dir = ft_strjoin_arg("%f %s %s", first->dir, "/",
				first->name);
			ft_printf("\n");
			ft_printf("%s:\n", first->dir);
			ft_open_and_read_dir(kl, first->dir);
		}
		first = first->next;
	}
//	ft_delete_lists(temp);
}

void	ft_print_dir(t_keylist *kl, t_fin *first)
{
	size_t	len;
	t_fin	*temp;

	len = 0;
	temp = first;
	while (first->next != NULL)
	{
		if (ft_strlen(first->name) > len)
			len = ft_strlen(first->name);
		first = first->next;
	}
	if (len % 8 == 0)
		len++;
	while (len % 8 != 0)
		len++;
	kl->maxsize->name = len;
	if (((kl->isfile > 0) && (kl->t_first == NULL)) ||
		((kl->dirnbr > 1) && (kl->t_first == NULL)))
		ft_printf("%s:\n", first->dir);
	if ((kl->l == 1) && (kl->t_first == NULL))
		ft_printf("total %i\n", kl->maxsize->total);
	ft_printing(kl, temp);
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

void	ft_sort_t_fin(t_keylist *kl, t_fin **list, int (*cmp)())
{
	t_fin	*first;
	t_fin	*a;
	t_fin	*b;

	first = *list;
	if (first && first->next)
	{
		ft_split_t_fin(first, &a, &b);
		ft_sort_t_fin(kl, &a, (*cmp));
		ft_sort_t_fin(kl, &b, (*cmp));
		*list = ft_merge(a, b, (*cmp));
	}
	(void)kl; //not used
}
