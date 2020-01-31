/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:27:48 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 18:08:41 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_error(t_keylist *kl, char *cur)
{
	/*
	char	*err;
	char	*str;

	err = strerror(errno);
	str = ft_strjoin_arg("%s %s %s %s %s %s", kl->programm_name, ": ",
							cur, ": ", err, "\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str); */
	ft_printf("%s: %s: %s\n", kl->programm_name, cur, strerror(errno));
}

void	ft_print_illegal_option(char *filename, char c)
{
	ft_printf("%s: illegal option -- %c\n", filename, c);
	ft_printf("usage: %s [-ACGLRSafglortu1] [file ...]\n", filename);
}
