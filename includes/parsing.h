/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:30:04 by eboris            #+#    #+#             */
/*   Updated: 2020/01/23 17:47:24 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "keylist.h"

t_keylist	*ft_ls_parsing_key(int argc, char **argv);
void		ft_ls_writedir(t_keylist *kl, char *argv);
int			ft_ls_key(t_keylist *kl, char *argv);
int			ft_ls_key_if_1(t_keylist *kl, char k);
int			ft_ls_key_if_2(t_keylist *kl, char k);

#endif
