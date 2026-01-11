/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:13:08 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/11 09:44:31 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

//#define malloc(x) test_malloc(x)

void	set_malloc_fail_at(int n);
void	*test_malloc(size_t size);

typedef	struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				lis;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

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
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rev_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	push(t_node **dst, t_node **src);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);

/* Sort main */
void	sort(t_node **stack_a, t_node **stack_b, int size);
int		check_sorted(t_node *stack);
void	sort_three(t_node **stack);
void	sort_big(t_node **stack_a, t_node **stack_b);

/* Sort LIS */

/* General utilities */
void	error_exit(long *arr, t_node **stack_a, t_node **stack_b);
void	free_arr_str(char **arr);

#endif
