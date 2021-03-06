/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:58:13 by eboris            #+#    #+#             */
/*   Updated: 2020/01/29 18:00:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>

int main(void)
{
   time_t t;

   time(&t);
   printf("The time is %s, unix-time is %ld\n", ctime(&t), t);
   return (0);
}
