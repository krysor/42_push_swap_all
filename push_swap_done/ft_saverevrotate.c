/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saverevrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:17:44 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 13:55:58 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_revrotate(t_list **lst);

char	*ft_saverevrotate(t_list **lst, char *result, char *str)
{
	char	*new_str;

	ft_revrotate(lst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}

static void	ft_revrotate(t_list **lst)
{
	t_list	*old_last;
	t_list	*new_last;
	int		size;

	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	old_last = ft_lstlast(*lst);
	size = ft_lstsize(*lst);
	new_last = *lst;
	while (size > 2)
	{
		new_last = new_last->next;
		size--;
	}
	new_last->next = NULL;
	ft_lstadd_front(lst, old_last);
}
