/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:44 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 13:50:18 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve_exit(char *result, t_list **a, t_list **b);
static char	*ft_sort(char *result, t_list **a, t_list **b);
static char	*ft_pballbutx(t_list **src, t_list **dst, int x, char *result);

char	*ft_solve(char *result, t_list **a)
{
	t_list	**b;

	if (ft_issorted(a))
		return (result);
	b = (t_list **)malloc(sizeof(t_list *));
	if (b == NULL)
		ft_solve_exit(result, a, b);
	*b = NULL;
	if (ft_iscis(a))
	{
		result = ft_cistosorted(a, result);
		if (!result)
			ft_solve_exit(result, a, b);
		ft_lstclear(a, (void *)free);
		ft_lstclear(b, (void *)free);
		free(b);
		return (result);
	}
	result = ft_sort(result, a, b);
	if (!result)
		ft_solve_exit(result, a, b);
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(b);
	return (result);
}

static void	ft_solve_exit(char *result, t_list **a, t_list **b)
{
	if (result != NULL)
		free(result);
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(a);
	free(b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static char	*ft_sort(char *result, t_list **a, t_list **b)
{
	result = ft_pballbutx(a, b, 3, result);
	if (!result)
		ft_solve_exit(result, a, b);
	if (!ft_iscis(a))
		result = ft_saveswap(a, result, "sa\n\0");
	if (!result)
		ft_solve_exit(result, a, b);
	while (ft_lstsize(*b) != 0)
	{
		result = ft_putbest(a, b, result);
		if (!result)
			ft_solve_exit(result, a, b);
	}
	if (!ft_issorted(a))
		result = ft_cistosorted(a, result);
	if (!result)
		ft_solve_exit(result, a, b);
	return (result);
}

static char	*ft_pballbutx(t_list **src, t_list **dst, int x, char *result)
{
	int		i;
	char	*new_result;

	i = ft_lstsize(*src);
	if (x < 0)
		x = 0;
	new_result = result;
	while (i > x)
	{	
		new_result = ft_savepush(src, dst, new_result, "pb\n\0");
		if (!new_result)
			return (NULL);
		i--;
	}
	return (new_result);
}
