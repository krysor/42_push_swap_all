/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:11 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:57:15 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_savethebestmoves(t_list *ra, t_list *rra,
				t_list *rb, t_list *rrb);
static int	ft_getnbleastmoves(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb);
static int	ft_getnbmoves(t_list *ra, t_list *rra, t_list *rb, t_list *rrb);
static int	ft_one(int nb);

int	*ft_getthebestmoves(t_list **ra, t_list **rra, t_list **rb, t_list **rrb)
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
		if (ft_getnbleastmoves(ra, rra, rb, rrb)
			== ft_getnbmoves(tempra, temprra, temprb, temprrb))
			return (ft_savethebestmoves(tempra, temprra, temprb, temprrb));
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
	return (NULL);
}

static int	*ft_savethebestmoves(t_list *ra, t_list *rra,
				t_list *rb, t_list *rrb)
{
	int	*bestmoves;

	bestmoves = malloc(sizeof(int) * 4);
	if (!bestmoves)
		return (NULL);
	bestmoves[0] = *(int *)(ra->content);
	bestmoves[1] = *(int *)(rra->content);
	bestmoves[2] = *(int *)(rb->content);
	bestmoves[3] = *(int *)(rrb->content);
	return (bestmoves);
}

static int	ft_getnbleastmoves(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb)
{
	int		least_moves;
	t_list	*tempra;
	t_list	*temprra;
	t_list	*temprb;
	t_list	*temprrb;

	tempra = *ra;
	temprra = *rra;
	temprb = *rb;
	temprrb = *rrb;
	least_moves = ft_getnbmoves(tempra, temprra, temprb, temprrb);
	while (tempra)
	{
		if (ft_getnbmoves(tempra, temprra, temprb, temprrb) < least_moves)
			least_moves = ft_getnbmoves(tempra, temprra, temprb, temprrb);
		tempra = tempra->next;
		temprra = temprra->next;
		temprb = temprb->next;
		temprrb = temprrb->next;
	}
	return (least_moves);
}

static int	ft_getnbmoves(t_list *tempra, t_list *temprra,
				t_list *temprb, t_list *temprrb)
{
	int	rarb;
	int	rarrb;
	int	rrarb;
	int	rrarrb;

	rarb = ft_max(ft_one(*(int *)(tempra->content)),
			ft_one(*(int *)(temprb->content)));
	rarrb = ft_one(*(int *)(tempra->content))
		+ ft_one(*(int *)(temprrb->content));
	rrarb = ft_one(*(int *)(temprra->content))
		+ ft_one(*(int *)(temprb->content));
	rrarrb = ft_max(ft_one(*(int *)(temprra->content)),
			ft_one(*(int *)(temprrb->content)));
	if (rarb <= rarrb && rarb <= rrarb && rarb <= rrarrb)
		return (rarb);
	else if (rarrb <= rarb && rarrb <= rrarb && rarrb <= rrarrb)
		return (rarrb);
	else if (rrarb <= rarb && rrarb <= rarrb && rrarb <= rrarrb)
		return (rrarb);
	else
		return (rrarrb);
}

static int	ft_one(int nb)
{
	if (nb == -1)
		return (INT_MAX / 2);
	return (nb);
}
