/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:00:20 by geliz             #+#    #+#             */
/*   Updated: 2020/01/26 17:20:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_file_info(struct stat buff, t_fin *first, int xattr)
{
	first->chmod = ft_check_access_rights(buff, xattr);
	return (1);
}
