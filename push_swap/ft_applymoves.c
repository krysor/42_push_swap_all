/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applymoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:04:03 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/29 10:55:54 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_applymove_one(t_list **a, t_list **b, char *move, int l);
static void	ft_applymove_two(t_list **a, t_list **b, char *move, int l);
static void	ft_applymoves_exit(t_list **a, t_list **b, char *move);
static char	*ft_add_nl(char *s1);

t_list	**ft_applymoves(t_list **a)
{
	char	*move;
	t_list	**b;

	move = NULL;
	b = (t_list **)malloc(sizeof(t_list *));
	if (b == NULL)
		ft_applymoves_exit(a, b, move);
	*b = NULL;
	move = ft_get_next_line(0);
	while (move)
	{
		if (move && move[ft_strlen(move) - 1] != '\n')
			move = ft_add_nl(move);
		ft_applymove_one(a, b, move, ft_strlen(move));
		free(move);
		move = ft_get_next_line(0);
	}
	ft_lstclear(b, (void *)free);
	free(b);
	return (a);
}

static void	ft_applymove_one(t_list **a, t_list **b, char *move, int l)
{
	if (l == (int)ft_strlen("pa\n") && !ft_strncmp(move, "pa\n", l))
		(void)ft_savepush(b, a, NULL, NULL);
	else if (l == (int)ft_strlen("pb\n") && !ft_strncmp(move, "pb\n", l))
		(void)ft_savepush(a, b, NULL, NULL);
	else if (l == (int)ft_strlen("sa\n") && !ft_strncmp(move, "sa\n", l))
		(void)ft_saveswap(a, NULL, NULL);
	else if (l == (int)ft_strlen("sb\n") && !ft_strncmp(move, "sb\n", l))
		(void)ft_saveswap(b, NULL, NULL);
	else if (l == (int)ft_strlen("ra\n") && !ft_strncmp(move, "ra\n", l))
		(void)ft_saverotate(a, NULL, NULL);
	else if (l == (int)ft_strlen("rb\n") && !ft_strncmp(move, "rb\n", l))
		(void)ft_saverotate(b, NULL, NULL);
	else if (l == (int)ft_strlen("rra\n") && !ft_strncmp(move, "rra\n", l))
		(void)ft_saverevrotate(a, NULL, NULL);
	else if (l == (int)ft_strlen("rrb\n") && !ft_strncmp(move, "rrb\n", l))
		(void)ft_saverevrotate(b, NULL, NULL);
	else
		ft_applymove_two(a, b, move, l);
}

static void	ft_applymove_two(t_list **a, t_list **b, char *move, int l)
{
	if (l == (int)ft_strlen("ss\n") && !ft_strncmp(move, "ss\n", l))
	{
		(void)ft_saveswap(a, NULL, NULL);
		(void)ft_saveswap(b, NULL, NULL);
	}
	else if (l == (int)ft_strlen("rr\n") && !ft_strncmp(move, "rr\n", l))
	{
		(void)ft_saverotate(a, NULL, NULL);
		(void)ft_saverotate(b, NULL, NULL);
	}
	else if (l == (int)ft_strlen("rrr\n") && !ft_strncmp(move, "rrr\n", l))
	{
		(void)ft_saverevrotate(a, NULL, NULL);
		(void)ft_saverevrotate(b, NULL, NULL);
	}
	else
		ft_applymoves_exit(a, b, move);
}

static void	ft_applymoves_exit(t_list **a, t_list **b, char *move)
{
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(a);
	free(b);
	free(move);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static char	*ft_add_nl(char *s1)
{
	char	*s2;
	int		l;

	l = ft_strlen(s1);
	s2 = malloc(sizeof(char) * l + 2);
	if (!s2)
		return (NULL);
	s2 = ft_memcpy(s2, s1, l);
	s2[l] = '\n';
	s2[l + 1] = '\0';
	free(s1);
	return (s2);
}
