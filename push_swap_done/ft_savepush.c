/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savepush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:34:17 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 13:52:08 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **src, t_list **dst);

char	*ft_savepush(t_list **src, t_list **dst, char *result, char *str)
{
	char	*new_str;

	ft_push(src, dst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}

static void	ft_push(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, temp);
}
