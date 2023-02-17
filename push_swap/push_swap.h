/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:42:19 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 13:54:21 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" 
# include <limits.h>

t_list	**ft_parse(int argc, char *argv[]);
void	*ft_atopi(char *str);

char	*ft_solve(char *result, t_list **a);

int		ft_issorted(t_list **lst);
int		ft_iscis(t_list **lst);
char	*ft_cistosorted(t_list **lst, char *result);

char	*ft_putbest(t_list **a, t_list **b, char *result);
t_list	**ft_lstdup(t_list **lst);
int		ft_max(int nb1, int nb2);
void	ft_getallbestmoves(t_list **ra, t_list **rra,
			t_list **rb, t_list **rrb);
int		*ft_getthebestmoves(t_list **ra, t_list **rra,
			t_list **rb, t_list **rrb);
char	*ft_makethebestmoves(t_list **a, t_list **b, char *result, int *moves);

t_list	**ft_get_nb_ra(t_list **ra, t_list **a);
t_list	**ft_get_nb_rra(t_list **rra, t_list **a);
t_list	**ft_get_nb_rb(t_list **rb);
t_list	**ft_get_nb_rrb(t_list **rrb);

char	*ft_saveswap(t_list **lst, char *result, char *str);
char	*ft_savepush(t_list **src, t_list **dst, char *result, char *str);
char	*ft_saverotate(t_list **lst, char *result, char *str);
char	*ft_saverevrotate(t_list **lst, char *result, char *str);

#endif