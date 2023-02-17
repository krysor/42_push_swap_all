/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:56:05 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/29 10:43:23 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_issorted(t_list **lst);
t_list	**ft_parse(int argc, char *argv[]);
t_list	**ft_applymoves(t_list **lst);
char	*ft_get_next_line(int fd);
char	*ft_saveswap(t_list **lst, char *result, char *str);
char	*ft_savepush(t_list **src, t_list **dst, char *result, char *str);
char	*ft_saverotate(t_list **lst, char *result, char *str);
char	*ft_saverevrotate(t_list **lst, char *result, char *str);

#endif