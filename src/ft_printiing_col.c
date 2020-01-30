/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printiing_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:37:55 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 19:07:51 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_printing_x(t_keylist *kl, t_fin *temp, int64_t *l)
{
	int	i;

	i = ft_ioctl();
	if (((kl->maxsize->name) * (*l + 1)) >= i)
	{
		ft_printf("\n");
		*l = 0;
	}
	ft_printf("%-*s", kl->maxsize->name, temp->name);
	return (1);
}

void		ft_printing_c_math(t_keylist *kl, t_fin *temp)
{
	t_fin	*t;
	int		i;
	int		n;
	int		y;
	int		z;

	t = temp;
	n = 0;
	i = ft_ioctl();
	while (t != NULL)
	{
		if ((t->type < 2) || (kl->a > 0) || ((kl->a_big > 0) && (t->type == 3)))
			n++;
		t = t->next;
	}
	z = i / (kl->maxsize->name);
	if (z != 0)
		y = n / z;
	else
		y = kl->maxsize->name;
	if ((z != 0) && ((n % z) != 0))
		y++;
	printf("col = %i, row = %i, total files = %i\n", z, y, n); //remove!!!
	kl->maxsize->col = z;
	kl->maxsize->row = y;
	kl->maxsize->totalfile = n;
}

int		ft_printing_c(t_keylist *kl, t_fin *temp)
{
	t_fin	*t;
	int		i;
	int		z;

	i = 2;
	ft_printing_c_math(kl, temp);
	ft_printf("%-*s", kl->maxsize->name, temp->name);
	while (i < kl->maxsize->totalfile)
	{
		t = temp;
		z = 0;
		while (z != i)
		{
			z++;
		}
		i++;
	}
	return (1);
}
