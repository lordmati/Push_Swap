/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:46:36 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/22 20:27:27 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_instruction(char *str, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(stack_b);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_b, stack_a);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
}

int	ft_valid_instruction(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (0);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (0);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (0);
	else
		return (1);
}

void	ft_read_instruction(t_node **stack_a, t_node **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_valid_instruction(str) == 0)
		{
			ft_instruction(str, stack_a, stack_b);
			free(str);
		}
		else
		{
			free(str);
			ft_show_error();
		}
	}
	ft_check_instruction(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	ft_check_instruction(t_node **stack_a, t_node **stack_b)
{
	if (ft_list_size(*stack_b) == 0 && ft_is_order(*stack_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
