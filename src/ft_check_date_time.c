/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_date_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:04:48 by eboris            #+#    #+#             */
/*   Updated: 2020/02/09 17:26:30 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_time_six_months(int t, char *src, char *str)
{
	time_t	c_time;

	time(&c_time);
	if (((c_time - t) > 15778463) || ((c_time - t) < 0))
	{
		ft_time_10000(src, str);
	}
	else
	{
		str[7] = src[11];
		str[8] = src[12];
		str[9] = src[13];
		str[10] = src[14];
		str[11] = src[15];
	}
	return (1);
}

int		ft_time_10000(char *src, char *str)
{
	str[7] = ' ';
	if ((src[20] == ' ') && (src[21] == ' ') &&
		(src[22] == ' ') && (src[23] == ' '))
	{
		str[8] = src[24];
		str[9] = src[25];
		str[10] = src[26];
		str[11] = src[27];
		str[12] = src[28];
	}
	else
	{
		str[8] = src[20];
		str[9] = src[21];
		str[10] = src[22];
		str[11] = src[23];
		str[12] = '\0';
	}
	return (1);
}

char	*ft_time_pars(char *src, int t)
{
	char	*str;

	if ((str = ft_strnew(13)) == NULL)
		return (NULL);
	str[0] = src[4];
	str[1] = src[5];
	str[2] = src[6];
	str[3] = ' ';
	str[4] = src[8];
	str[5] = src[9];
	str[6] = ' ';
	if ((ft_time_six_months(t, src, str)) == 1)
		return (str);
	return (NULL);
}
