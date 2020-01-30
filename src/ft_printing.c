/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:10:19 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 12:37:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_printing(t_keylist *kl, t_fin *temp)
{
	if (kl->l == 1)
		ft_printing_l(kl, temp);
	else if (kl->one == 1)
		ft_printing_1(kl, temp);
	else if (kl->c_big == 1)
		ft_printing_c(kl, temp);
	else
		ft_printing_c(kl, temp);
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
	ft_printf("%s %*i %-*s  %-*s  %*lld %s %s\n", temp->info->chmod,
		kl->maxsize->type, temp->info->type, kl->maxsize->login,
		temp->info->login, kl->maxsize->group, temp->info->group,
		kl->maxsize->size, temp->info->size, temp->info->time, temp->name);
	return (1);
}
