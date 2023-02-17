/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:33 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/29 10:55:27 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	**input;
	int		l;

	if (argc <= 1)
		return (1);
	input = ft_parse(argc, argv);
	l = ft_lstsize(*input);
	input = ft_applymoves(input);
	if (ft_issorted(input) && ft_lstsize(*input) == l)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(input, (void *)free);
	free(input);
	return (1);
}
