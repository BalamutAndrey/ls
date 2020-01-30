/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_date_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:04:48 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 13:07:18 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_time_six_months(int t, char *src, char *str)
{
	time_t	c_time;

	time(&c_time);
	if (((c_time - t) > 15778463) || ((c_time - t) < 0))
	{
		str[7] = ' ';
		str[8] = src[20];
		str[9] = src[21];
		str[10] = src[22];
		str[11] = src[23];
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

char	*ft_time_pars(char *src, int t)
{
	char	*str;

	if ((str = ft_strnew(12)) == NULL)
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
