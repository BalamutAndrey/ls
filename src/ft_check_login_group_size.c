/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_login_group_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:45:46 by eboris            #+#    #+#             */
/*   Updated: 2020/01/29 16:46:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*ft_check_login(t_maxsize *maxsize, struct stat buff)
{
	char			*login;
	struct passwd	*pass;
	int				i;

	pass = getpwuid(buff.st_uid);
	login = ft_strdup(pass->pw_name);
	i = ft_strlen(login);
	if (i > maxsize->login)
		maxsize->login = i;
	return (login);
}

char					*ft_check_group(t_maxsize *maxsize, struct stat buff)
{
	char			*groupname;
	struct group	*group;
	int				i;

	group = getgrgid(buff.st_gid);
	groupname = ft_strdup(group->gr_name);
	i = ft_strlen(groupname);
	if (i > maxsize->group)
		maxsize->group = i;
	return (groupname);
}

unsigned long long int	ft_check_size(t_maxsize *maxsize, struct stat buff)
{
	unsigned long long int	n;
	int						i;

	n = buff.st_size;
	i = ft_nbrlen(n);
	if (i > maxsize->size)
		maxsize->size = i;
	return (n);
}
