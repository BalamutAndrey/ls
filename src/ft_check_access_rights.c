/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access_rights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:31:16 by geliz             #+#    #+#             */
/*   Updated: 2020/01/22 16:30:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_is_it_dir_file_link(char *str, struct stat buff)
{
	if (S_ISREG(buff.st_mode))
		str[0] = '-';
	if (S_ISLNK(buff.st_mode))
		str[0] = 'l';
	if (S_ISDIR(buff.st_mode))
		str[0] = 'd';
}

char	*ft_check_access_rights(struct stat buff)
{
	char	*str;

	if (!(str = ft_strnew(10)))
		return (NULL);
	ft_is_it_dir_file_link(str, buff);
	str[1] = buff.st_mode & S_IRUSR ? 'r' : '-';
	str[2] = buff.st_mode & S_IWUSR ? 'w' : '-';
	str[3] = buff.st_mode & S_IXUSR ? 'x' : '-';
	str[4] = buff.st_mode & S_IRGRP ? 'r' : '-';
	str[5] = buff.st_mode & S_IWGRP ? 'w' : '-';
	str[6] = buff.st_mode & S_IXGRP ? 'x' : '-';
	str[7] = buff.st_mode & S_IROTH ? 'r' : '-';
	str[8] = buff.st_mode & S_IWOTH ? 'w' : '-';
	str[9] = buff.st_mode & S_IXOTH ? 'x' : '-';
	return (str);
}