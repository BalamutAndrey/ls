/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_date_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:04:48 by eboris            #+#    #+#             */
/*   Updated: 2020/01/30 11:29:57 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_time_six_months(int time)
{
	time_t	c_time;

	time(&c_time);
	if (((c_time - time) > 15778463) || ((c_time - time) < 0))
		return (1);
	return (0);
}
