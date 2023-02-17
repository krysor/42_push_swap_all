/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cistosorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:56:10 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 11:14:12 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_cistosorted(t_list **lst, char *result)
{
	t_list	*temp;
	int		tie;

	temp = *lst;
	tie = 0;
	while (temp->next)
	{
		if (*(int *)(temp->content) > *(int *)((temp->next)->content))
			break ;
		tie++;
		temp = temp->next;
	}
	if (tie < ft_lstsize(*lst) / 2)
	{
		while (result != NULL && !ft_issorted(lst))
			result = ft_saverotate(lst, result, "ra\n\0");
	}	
	else
	{
		while (result != NULL && !ft_issorted(lst))
			result = ft_saverevrotate(lst, result, "rra\n\0");
	}
	return (result);
}
