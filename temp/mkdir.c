/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:32:07 by eboris            #+#    #+#             */
/*   Updated: 2020/01/22 13:34:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
	
int	main(int argc, char **argv)
{
	DIR				*dp;
	struct dirent	*ep;
 
	if (argc == 1)
	{
		dp = opendir("./");
	}
	else if (argc == 2)
	{
		dp = opendir(argv[1]);
	}
	else
	{
		printf("bad parameters");
		return (0);
	}
	if (dp != NULL)
	{
		while ((ep = readdir(dp)) != 0)
		{
			printf("%s\n", ep->d_name);
		}
		closedir(dp);
	}
	else
	{
		printf("error");
	}
 	return (0);
}
