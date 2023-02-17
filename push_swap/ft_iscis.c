/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:55:09 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 16:59:15 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_iscis(t_list **lst)
{
	t_list	*temp;
	int		p;
	int		first;

	if (ft_lstsize(*lst) <= 1 || ft_issorted(lst))
		return (1);
	temp = *lst;
	first = *(int *)(temp->content);
	p = 1;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
		{
			if (!p)
				return (0);
			p = 0;
		}
		temp = temp->next;
	}
	if (first > *(int *)(temp->content))
		return (1);
	return (0);
}
