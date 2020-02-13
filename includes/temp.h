#ifndef TEMP_H
# define TEMP_H
# include "ft_ls.h"
void	ft_sort_dirkeylist(t_dirkeylist **list, int (*cmp)());;
t_dirkeylist	*ft_merge_dirkeylist(t_dirkeylist *a, t_dirkeylist *b, int (*cmp)());
void	ft_split_t_dirkeylist(t_dirkeylist *first, t_dirkeylist **a, t_dirkeylist **b);
void	ft_sort_arg_dirs(t_keylist *kl);
int		ft_dirkeylist_alphabet_sort(t_dirkeylist *a, t_dirkeylist *b);
int		ft_dirkeylist_alphabet_rev_sort(t_dirkeylist *a, t_dirkeylist *b);

#endif