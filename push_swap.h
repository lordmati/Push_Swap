/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:54:38 by misaguir          #+#    #+#             */
/*   Updated: 2024/03/19 16:51:50 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_node
{
	int				pos;
	int				index;
	int				target_pos;
	int				number;
	int				cost_a;
	int				cost_b;
	int				cost_total;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum e_move
{
	SA = 1,
	RA = 2,
	RRA = 3,
	PB = 4,
	SB = 5,
	RB = 6,
	RRB = 7,
	RR = 8,
	RRR = 9,
	SS = 10,
	PA = 11
}	t_move;

////////UTILS////////
int		ft_abs(int n);
void	ft_onearg(char **argv);
int		ft_verification(char *str);
void	ft_multarg(int argc, char **argv);
void	ft_convertnumbers(int argc, char **argv, int i);
int		ft_repeatnumbers(int *tab, int len);
long	ft_atol(const char *str);
void	ft_setup(int argc, int *tab);
void	ft_num_max(long nbr);
t_node	*new_node(int number);
t_node	*ft_stack_a(int *arr, int len);
void	ft_show_error(void);
int		ft_list_size(t_node *stack);
int		ft_find_lower_index(t_node *stack);
void	free_stack(t_node **head);
void	ft_free_matrix(char **str);
/////MOVEMENTS/////
void	sa(t_node **head);
void	ra(t_node **head);
void	rra(t_node **head);
void	pa(t_node **head_b, t_node **head);
void	add_to_head(t_node **head_b, t_node **head);
void	remove_node(t_node **head_b);
void	pb(t_node **head, t_node **head_b);
void	sb(t_node **head_b);
void	rb(t_node **head_b);
void	rrb(t_node **head_b);
void	rr(t_node **head, t_node **head_b);
void	rrr(t_node **head, t_node **head_b);
/////MOVEMENTS PRINTS/////
void	move_prints(t_node **stack_a, t_node **stack_b, t_move mov);
void	move_prints_b(t_node **stack_a, t_node **stack_b, t_move mov);
////////////ORDER//////////
int		ft_is_order(t_node *head);
void	ft_sort_three(t_node **stack_a);
void	ft_calc_index(t_node **stack_a, int len, int size, int aux_len);
void	ft_calc_position(t_node **stack_a, int len);
void	ft_target_find(t_node **stack_a, t_node **stack_b);
int		ft_target_find_norm(t_node **aux_a, t_node **aux_b, int size_a);
void	ft_push_all_b(t_node **stack_a, t_node **stack_b, int len);
void	ft_cost(t_node **stack_a, t_node **stack_b, int len);
int		ft_cost_top(t_node **stack, int pos);
void	ft_final_moves(t_node **stack_a, t_node **stack_b, t_node *low_cost_b);
void	ft_moves_stacks(t_node **stack_a, t_node **stack_b, int len);
void	ft_move_rotate_a(t_node **stack_a, t_node **stack_b, int *cost);
void	ft_move_rotate_b(t_node **stack_a, t_node **stack_b, int *cost);
void	ft_final_step(t_node **stack_a, t_node **stack_b);
void	ft_move_rotate_rr(t_node **st_a, t_node **st_b, int *c_a, int *c_b);
void	ft_move_rotate_rrr(t_node **st_a, t_node **st_b, int *c_a, int *c_b);
void	ft_final_order(t_node **stack_a, t_node **stack_b, int aux);

#endif