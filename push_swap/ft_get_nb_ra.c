/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:51:11 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 10:26:31 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_nb_ra_inloop(t_list *tempa, t_list *tempra,
				t_list **a, int i);
static int	ft_ra_iszero(t_list *tempra, t_list **a);
static int	ft_ra_iselse(t_list *tempra, t_list *tempa);

t_list	**ft_get_nb_ra(t_list **ra, t_list **a)
{
	int		i;
	t_list	*tempa;
	t_list	*tempra;

	if (ra == NULL)
		return (NULL);
	tempra = *ra;
	while (tempra)
	{
		i = 1;
		tempa = *a;
		ft_get_nb_ra_inloop(tempa, tempra, a, i);
		tempra = tempra->next;
	}
	return (ra);
}

static void	ft_get_nb_ra_inloop(t_list *tempa, t_list *tempra,
			t_list **a, int i)
{
	while (tempa)
	{
		if (ft_ra_iszero(tempra, a))
		{
			*(int *)(tempra->content) = 0;
			break ;
		}
		if (ft_ra_iselse(tempra, tempa))
		{
			*(int *)(tempra->content) = i;
			break ;
		}
		i++;
		tempa = tempa->next;
	}
}

static int	ft_ra_iszero(t_list *tempra, t_list **a)
{
	if (ft_lstsize(*a) == 1)
		return (1);
	if (ft_issorted(a))
	{
		if (*(int *)(tempra->content) < *(int *)((*a)->content))
			return (1);
		if (*(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content))
			return (1);
	}
	if (*(int *)(tempra->content) < *(int *)((*a)->content)
		&& *(int *)(tempra->content) > *(int *)(ft_lstlast((*a))->content))
		return (1);
	return (0);
}

static int	ft_ra_iselse(t_list *tempra, t_list *tempa)
{
	if (tempa->next != NULL)
	{
		if (*(int *)(tempa->content) < *(int *)(tempra->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
			return (1);
		if (*(int *)(tempa->content) > *(int *)((tempa->next)->content))
		{
			if (*(int *)(tempra->content) < *(int *)(tempa->content)
		&& *(int *)(tempra->content) < *(int *)((tempa->next)->content))
				return (1);
			if (*(int *)(tempra->content) > *(int *)(tempa->content)
		&& *(int *)(tempra->content) > *(int *)((tempa->next)->content))
				return (1);
		}
	}
	return (0);
}
