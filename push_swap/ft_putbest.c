/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:52:24 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 15:17:08 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_putbest_free_return(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb);
static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb);
static void	ft_putbest_free_lst(t_list **lst);

char	*ft_putbest(t_list **a, t_list **b, char *result)
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;
	int		*moves;

	ra = ft_get_nb_ra(ft_lstdup(b), a);
	rra = ft_get_nb_rra(ft_lstdup(b), a);
	rb = ft_get_nb_rb(ft_lstdup(b));
	rrb = ft_get_nb_rrb(ft_lstdup(b));
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
		return (ft_putbest_free_return(ra, rra, rb, rrb));
	ft_getallbestmoves(ra, rra, rb, rrb);
	moves = ft_getthebestmoves(ra, rra, rb, rrb);
	if (!moves)
		return (ft_putbest_free_return(ra, rra, rb, rrb));
	result = ft_makethebestmoves(a, b, result, moves);
	ft_putbest_free(ra, rra, rb, rrb);
	free(moves);
	return (result);
}

static char	*ft_putbest_free_return(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb)
{
	ft_putbest_free(ra, rra, rb, rrb);
	return (NULL);
}

static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb)
{
	ft_putbest_free_lst(ra);
	ft_putbest_free_lst(rra);
	ft_putbest_free_lst(rb);
	ft_putbest_free_lst(rrb);
}

static void	ft_putbest_free_lst(t_list **lst)
{
	int	p;

	p = 1;
	if (!lst)
		p = 0;
	ft_lstclear(lst, (void *)free);
	if (p)
		free(lst);
}
