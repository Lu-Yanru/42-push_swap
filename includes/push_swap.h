/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:13:08 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/14 18:41:53 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

//#define malloc(x) test_malloc(x)
#include <stdio.h>

void	set_malloc_fail_at(int n);
void	*test_malloc(size_t size);

typedef struct s_node
{
	int				value;
	int				index;
	int				lis;
	struct s_node	*lis_prev;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_move
{
	int	size_a;
	int	size_b;
	int	index;
	int	target_index;
	int	cost_a;
	int	cost_b;
	int	cost_all;
	int	cost_shared;
}	t_move;

/* Check validity of input */

int		check_args(int argc, char *argv[], long **arr, int *size);
int		check_digits(char *str);
int		check_unique_n_range(long *arr, int count);
char	*build_arg_str(int argc, char *argv[]);
long	*create_number_array(char *str, int *count);
int		is_sign(char c);
int		count_numbers(char *str);
long	*store_numbers(char *str, long *arr);
long	ft_atol(char *str);
char	*ft_join_n_free(char *s1, char *s2);

/* Initialize stack */
void	stack_init(t_node **stack_a, long *arr, int size);
t_node	*new_node(int value);
void	add_top(t_node **stack, t_node *new);
t_node	*last_node(t_node *stack);
void	add_bottom(t_node **stack, t_node *new);

/* Stack utilities */
void	free_node(t_node *node);
void	free_stack(t_node **stack);

/* Operations */
void	swap(t_node **stack);
void	sa(t_node **stack_a, int n);
void	sb(t_node **stack_b, int n);
void	ss(t_node **stack_a, t_node **stack_b, int n);
void	rotate(t_node **stack);
void	ra(t_node **stack_a, int n);
void	rb(t_node **stack_b, int n);
void	rr(t_node **stack_a, t_node **stack_b, int n);
void	rev_rotate(t_node **stack);
void	rra(t_node **stack_a, int n);
void	rrb(t_node **stack_b, int n);
void	rrr(t_node **stack_a, t_node **stack_b, int n);
void	push(t_node **dst, t_node **src);
void	pa(t_node **stack_a, t_node **stack_b, int n);
void	pb(t_node **stack_b, t_node **stack_a, int n);

/* Sort main */
void	sort(t_node **stack_a, t_node **stack_b, int size);
int		check_sorted(t_node *stack);
void	sort_three(t_node **stack);
void	sort_big(t_node **stack_a, t_node **stack_b, int size);
void	push_to_b(t_node **stack_a, t_node **stack_b, t_move *move);
void	do_ops(t_node **stack_src, t_node **stack_dst, t_move *move, int direction);

/* Sort LIS */
void	find_lis(t_node **stack, int *lis_size, int stack_size);
int		init_tail_arrs(int **tail_val, t_node ***tail, int stack_size);
int		binary_search_lis(int *tail_val, int left, int right, int value);
void	mark_lis(t_node **tail, int lis_size);

/* Sort cost */
void	calc_cost(t_node **stack_a, t_node **stack_b, t_move *move, int direction);
void	assign_index(t_node **stack);
int		find_target_ascend(t_node *stack, int value);
int		find_target_descend(t_node *stack, int value);
int		get_smallest_index(t_node *stack);
int		get_biggest_index(t_node *stack);

/* General utilities */
void	error_exit(long *arr, t_node **stack_a, t_node **stack_b);
void	free_arr_str(char **arr);
int		ft_abs(int nbr);

#endif
