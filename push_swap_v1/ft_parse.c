/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:17:37 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/20 16:25:09 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_freearr(char **arr);
static t_list	**ft_atolst(char **arr, int argc);
static void		ft_atolst_exit(char **arr, int argc,
					t_list **lst, void *content);
static int		ft_islastdup(t_list **lst);

t_list	**ft_parse(int argc, char *argv[])
{
	char	**arr;
	t_list	**lst;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (arr == NULL || *arr == NULL)
		{
			if (*arr == NULL)
				ft_freearr(arr);
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
	}
	else
		arr = argv + 1;
	lst = ft_atolst(arr, argc);
	if (argc == 2)
		ft_freearr(arr);
	return (lst);
}

static void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	if (arr[i] != NULL)
	{
		while (arr[i] != NULL)
			i++;
		while (i >= 0)
			free(arr[i--]);
	}
	free(arr);
}

static t_list	**ft_atolst(char **arr, int argc)
{
	int		i;
	t_list	**lst;
	void	*content;

	i = 0;
	lst = (t_list **)malloc(sizeof(t_list *));
	if (lst != NULL)
		*lst = NULL;
	while (arr[i] != NULL)
	{	
		if (lst != NULL)
		{
			content = ft_atopi(arr[i]);
			ft_lstadd_back(lst, ft_lstnew(content));
		}
		if (lst == NULL || ft_lstsize(*lst) != i + 1
			|| ft_lstlast(*lst)->content == NULL || ft_islastdup(lst))
			ft_atolst_exit(arr, argc, lst, content);
		i++;
	}
	return (lst);
}

static void	ft_atolst_exit(char **arr, int argc, t_list **lst, void *content)
{
	if (argc == 2)
		ft_freearr(arr);
	if (content != NULL
		&& *(int *)(ft_lstlast(*lst)->content) != *(int *)content)
		free(content);
	ft_lstclear(lst, (void *)free);
	free(lst);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static int	ft_islastdup(t_list **lst)
{
	int		nb;
	int		count;
	t_list	*l;

	if (lst == NULL || *lst == NULL)
		return (1);
	nb = *(int *)(ft_lstlast(*lst)->content);
	count = 0;
	l = *lst;
	while (l != NULL)
	{
		if (*(int *)(l->content) == nb)
			count++;
		l = l->next;
	}
	if (count == 1)
		return (0);
	return (1);
}
