/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:01 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/19 20:17:37 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc == 1)
		return (0);
	if (argc == 2)
		ft_onearg(argv);
	else
		ft_multarg(argc, argv);
}
