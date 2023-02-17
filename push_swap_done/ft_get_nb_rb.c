/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_rb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:49:55 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:29:50 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_get_nb_rb(t_list **rb)
{
	t_list	*temp;
	int		i;

	if (rb == NULL)
		return (NULL);
	i = 0;
	temp = *rb;
	while (temp)
	{
		*(int *)(temp->content) = i;
		i++;
		temp = temp->next;
	}
	return (rb);
}
