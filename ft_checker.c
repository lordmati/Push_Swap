/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:55:01 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/11 20:13:52 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_onearg(char **argv)
{
	int		i;
	int		nbr;
	int		count;
	char	**str;

	i = 0;
	nbr = 0;
	count = 0;
	str = ft_split(argv[1], ' ');
	if (!str[i])
		ft_show_error();
	while (str[count])
		count++;
	while (ft_verification(str[i]) == 1 && i < count - 1)
		i++;
	if (ft_verification(str[i]) == 0)
		ft_show_error();
	ft_convertnumbers(count, str, 0);
}

void	ft_multarg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (ft_verification(argv[i]) == 1 && i < argc - 1)
		i++;
	if (ft_verification(argv[i]) == 0)
		ft_show_error();
	ft_convertnumbers(argc - 1, argv, 1);
}

void	ft_convertnumbers(int argc, char **argv, int i)
{
	int	*tab;
	int	j;

	j = 0;
	tab = (int *)(malloc(sizeof(int) * argc));
	if (tab == NULL)
		exit(0);
	while (argv[i] != NULL)
	{
		tab[j] = ft_atol(argv[i]);
		j++;
		i++;
	}
	if (argc == 1)
		return ;
	ft_setup(argc, tab);
}

void	ft_setup(int argc, int *tab)
{
	int i;
	i = 0;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_repeatnumbers(tab, argc) == 0)
		ft_show_error();
	else
		stack_a = ft_stack_a(tab, argc);
	if (ft_is_order(stack_a) == 1)
			exit(0);
	if (argc == 2)
		move_prints(&stack_a, &stack_b, 1);
	else if (argc == 3)
		ft_sort_three(&stack_a);
	ft_calc_index(&stack_a,argc + 1, argc ,argc);
	ft_push_all_b(&stack_a,&stack_b,ft_list_size(stack_a));
	ft_sort_three(&stack_a);
/* 	ft_target_find(&stack_a,&stack_b);
	ft_cost(&stack_a,&stack_b,ft_list_size(stack_b));
	printeo_b(&stack_b,ft_list_size(stack_b)); */
/* 	move_prints_b(&stack_b,&stack_a,PA);
	move_prints_b(&stack_b,&stack_a,PA);
	printf("tamaño a: %d\n", ft_list_size(stack_a));
	printf("tamaño b: %d\n",ft_list_size(stack_b)); */
	printeo(&stack_a,3);
	while(ft_list_size(stack_b) > 0)
	{
		ft_target_find(&stack_a,&stack_b);
		ft_cost(&stack_a,&stack_b,ft_list_size(stack_b));
		ft_moves_stacks(&stack_a,&stack_b,ft_list_size(stack_b));
	}
	printeo(&stack_a,ft_list_size(stack_a));
}

void	ft_sort_three(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if ((*stack_a)->number < (*stack_a)->next->number
		&& (*stack_a)->number > (*stack_a)->next->next->number)
	{
		move_prints(stack_a, &stack_b, RRA);
		return ;
	}
	if (((*stack_a)->number < (*stack_a)->next->number
			&& (*stack_a)->number > (*stack_a)->next->next->number)
		|| ((*stack_a)->number < (*stack_a)->next->number
			&& (*stack_a)->number < (*stack_a)->next->next->number))
		move_prints(stack_a, &stack_b, SA);
	if ((*stack_a)->number > (*stack_a)->next->number
		&& (*stack_a)->number > (*stack_a)->next->next->number)
		move_prints(stack_a, &stack_b, RA);
	if ((*stack_a)->number > (*stack_a)->next->number)
		move_prints(stack_a, &stack_b, SA);
}
