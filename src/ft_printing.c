/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:10:19 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 15:34:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_printing(t_keylist *kl, t_fin *temp)
{
	if ((temp->type < 2) || (kl->a > 0) ||
		((kl->a_big > 0) && (temp->type == 3)))
	{
		if (kl->l == 1)
			ft_printing_l(kl, temp);
		else if (kl->one == 1)
			ft_printing_1(kl, temp);
		else if (kl->c_big == 1)
			ft_printing_c(kl, temp);
		else
			ft_printing_c(kl, temp);
	}
	return (1);
}

int	ft_printing_c(t_keylist *kl, t_fin *temp)
{
	ft_printf("%-*s ", kl->maxsize->name, temp->name);
	return (1);
}

int	ft_printing_1(t_keylist *kl, t_fin *temp)
{
	ft_printf("%-*s\n", kl->maxsize->name, temp->name);
	return (1);
}

int	ft_printing_l(t_keylist *kl, t_fin *temp)
{
	ft_printf("%s %*i ", temp->info->chmod,
		kl->maxsize->type, temp->info->type);
	if (kl->g == 0)
		ft_printf("%-*s  ", kl->maxsize->login, temp->info->login);
	if (kl->o == 0)
		ft_printf("%-*s  ", kl->maxsize->group, temp->info->group);
	if ((kl->g == 1) && (kl->o == 1))
		ft_printf("  ");
	ft_printf("%*lld %s %s\n", kl->maxsize->size, temp->info->size,
				temp->info->time, temp->name);
	return (1);
}
