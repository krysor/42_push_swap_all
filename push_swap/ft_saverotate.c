/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saverotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:18:37 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 13:52:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **lst);

char	*ft_saverotate(t_list **lst, char *result, char *str)
{
	char	*new_str;

	ft_rotate(lst);
	new_str = ft_strjoin(result, str);
	free(result);
	if (!new_str)
		return (NULL);
	return (new_str);
}

static void	ft_rotate(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || ft_lstsize(*lst) <= 1)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}
