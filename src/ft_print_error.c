/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:27:48 by geliz             #+#    #+#             */
/*   Updated: 2020/02/15 18:55:26 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_error(t_keylist *kl, char *cur)
{
	ft_fprintf(2, "ls: %s: %s\n", cur, strerror(errno));
	(void)kl;
}

void	ft_print_illegal_option(char *filename, char c)
{
	ft_fprintf(2, "ls: illegal option -- %c\n", c);
	ft_fprintf(2, "usage: ls [-ACGLRSafglortu1] [file ...]\n");
	(void)filename;
}
