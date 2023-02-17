/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getallbestmoves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:56:33 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:57:00 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_setbestmove(t_list *tempra, t_list *temprra,
				t_list *temprb, t_list *temprrb);
static void	ft_setworst(t_list *temp1, t_list *temp2);

void	ft_getallbestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
{
	t_list	*tempra;
	t_list	*temprra;
	t_list	*temprb;
	t_list	*temprrb;

	tempra = *ra;
	temprra = *rra;
	temprb = *rb;
	temprrb = *rrb;
	while (tempra)
	{
		ft_setbestmove(tempra, temprra, temprb, temprrb);
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
}

static void	ft_setbestmove(t_list *tempra, t_list *temprra,
				t_list *temprb, t_list *temprrb)
{
	int	rarb;
	int	rarrb;
	int	rrarb;
	int	rrarrb;

	rarb = ft_max(*(int *)(tempra->content), *(int *)(temprb->content));
	rarrb = *(int *)(tempra->content) + *(int *)(temprrb->content);
	rrarb = *(int *)(temprra->content) + *(int *)(temprb->content);
	rrarrb = ft_max(*(int *)(temprra->content), *(int *)(temprrb->content));
	if (rarb <= rarrb && rarb <= rrarb && rarb <= rrarrb)
		ft_setworst(temprra, temprrb);
	else if (rarrb <= rarb && rarrb <= rrarb && rarrb <= rrarrb)
		ft_setworst(temprra, temprb);
	else if (rrarb <= rarb && rrarb <= rarrb && rrarb <= rrarrb)
		ft_setworst(tempra, temprrb);
	else
		ft_setworst(tempra, temprb);
}

static void	ft_setworst(t_list *temp1, t_list *temp2)
{
	*(int *)(temp1->content) = -1;
	*(int *)(temp2->content) = -1;
}
