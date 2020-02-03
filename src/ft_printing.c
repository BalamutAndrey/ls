/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:10:19 by eboris            #+#    #+#             */
/*   Updated: 2020/02/03 17:30:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printing(t_keylist *kl, t_fin *temp)
{
	int64_t	l;

	l = 0;
	if ((kl->one != 1) && (kl->l != 1) && (kl->x != 1))
	{
		while ((temp) && (((temp->type == 2) && (kl->a == 0)) ||
			((kl->a_big == 0) && (temp->type == 3))))
			temp = temp->next;
		ft_printing_c(kl, temp);
	}
	while (temp != NULL)
	{
		if ((temp->type < 2) || (kl->a > 0) ||
			((kl->a_big > 0) && (temp->type == 3)))
		{
			if (kl->l == 1)
				ft_printing_l(kl, temp);
			else if (kl->one == 1)
				ft_printing_1(kl, temp);
			else if (kl->x == 1)
				ft_printing_x(kl, temp, &l);
			l++;
		}
		temp = temp->next;
	}
	if ((kl->one != 1) && (kl->l != 1))
		printf("\n");
}

int		ft_printing_1(t_keylist *kl, t_fin *temp)
{
	ft_printf("%-*s\n", kl->maxsize->name, temp->name);
	return (1);
}

int		ft_printing_l(t_keylist *kl, t_fin *temp)
{
	ft_printf("%s %*i ", temp->info->chmod,
		kl->maxsize->type, temp->info->type);
	if (kl->g == 0)
		ft_printf("%-*s  ", kl->maxsize->login, temp->info->login);
	if (kl->o == 0)
		ft_printf("%-*s  ", kl->maxsize->group, temp->info->group);
	if ((kl->g == 1) && (kl->o == 1))
		ft_printf("  ");
	ft_printf("%*lld %s %s", kl->maxsize->size, temp->info->size,
				temp->info->time, temp->name);
	if (temp->linkto != NULL)
		ft_printf(" -> %s", temp->linkto);
	ft_printf("\n");
	return (1);
}

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

int		ft_ioctl(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}
