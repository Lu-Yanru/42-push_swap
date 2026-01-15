/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:51:24 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/15 13:31:33 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that executes the 
@param direction The direction of sorting. 0 for descending, 1 for ascending.
*/
void	do_ops(t_node **stack_src, t_node **stack_dst, t_move *move, int direction)
{
	int	a_moves;
	int	b_moves;

	if (move->cost_shared > 0)
		rr(stack_src, stack_dst, move->cost_shared);
	else if (move->cost_shared < 0)
		rrr(stack_src, stack_dst, ft_abs(move->cost_shared));
	a_moves = ft_abs(move->cost_a) - ft_abs(move->cost_shared);
	b_moves = ft_abs(move->cost_b) - ft_abs(move->cost_shared);
	if (a_moves > 0)
	{
		if (move->cost_a > 0)
			ra(stack_src, a_moves);
		else
			rra(stack_src, a_moves);
	}
	if (b_moves > 0)
	{
		if (move->cost_b > 0)
			rb(stack_dst, b_moves);
		else
			rrb(stack_dst, b_moves);
	}
	if (direction == 0)
		pb(stack_dst, stack_src, 1);
	else
		pa(stack_dst, stack_src, 1);
}

/*
@brief A function that pushes each non-LIS node from stack a to stack b
in the order of descending cost.
*/
void	push_optimally(t_node **stack_a, t_node **stack_b, t_move *move, int direction)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->lis == 0)
		{
			printf("push node\n");
			assign_index(stack_a);
			assign_index(stack_b);
			calc_cost(stack_a, stack_b, move, direction);
			do_ops(stack_a, stack_b, move, direction);
			move->size_a--;
			move->size_b++;
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
	}
}
