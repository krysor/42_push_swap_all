/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_rrb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:55 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:31:53 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_get_nb_rrb(t_list **rrb)
{
	t_list	*temp;
	int		i;

	if (rrb == NULL)
		return (NULL);
	i = ft_lstsize(*rrb);
	temp = *rrb;
	while (temp)
	{
		*(int *)(temp->content) = i;
		i--;
		temp = temp->next;
	}
	*(int *)((*rrb)->content) = 0;
	return (rrb);
}
