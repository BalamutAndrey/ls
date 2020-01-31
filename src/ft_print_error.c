/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:27:48 by geliz             #+#    #+#             */
/*   Updated: 2020/01/31 17:19:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_error(char	*cur)
{
	char	*err;
	char	*str;

	
	err = strerror(errno);
	str = ft_strjoin_arg("%s %s %s %s %s", "ft_ls: ", cur, ": ", err, "\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
}
