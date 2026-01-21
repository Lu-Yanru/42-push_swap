/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:51:24 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/21 12:20:25 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_ops_asc(t_node **stk_src, t_node **stk_dst, t_move *move)
{
	int	src_moves;
	int	dst_moves;

	if (move->cost_shared > 0)
		rr(stk_src, stk_dst, move->cost_shared);
	else if (move->cost_shared < 0)
		rrr(stk_src, stk_dst, ft_abs(move->cost_shared));
	src_moves = ft_abs(move->cost_a) - ft_abs(move->cost_shared);
	dst_moves = ft_abs(move->cost_b) - ft_abs(move->cost_shared);
	if (src_moves > 0)
	{
		if (move->cost_a > 0)
			rb(stk_src, src_moves);
		else
			rrb(stk_src, src_moves);
	}
	if (dst_moves > 0)
	{
		if (move->cost_b > 0)
			ra(stk_dst, dst_moves);
		else
			rra(stk_dst, dst_moves);
	}
	pa(stk_dst, stk_src, 1);
}

static void	do_ops_desc(t_node **stk_src, t_node **stk_dst, t_move *move)
{
	int	src_moves;
	int	dst_moves;

	if (move->cost_shared > 0)
		rr(stk_src, stk_dst, move->cost_shared);
	else if (move->cost_shared < 0)
		rrr(stk_src, stk_dst, ft_abs(move->cost_shared));
	src_moves = ft_abs(move->cost_a) - ft_abs(move->cost_shared);
	dst_moves = ft_abs(move->cost_b) - ft_abs(move->cost_shared);
	if (src_moves > 0)
	{
		if (move->cost_a > 0)
			ra(stk_src, src_moves);
		else
			rra(stk_src, src_moves);
	}
	if (dst_moves > 0)
	{
		if (move->cost_b > 0)
			rb(stk_dst, dst_moves);
		else
			rrb(stk_dst, dst_moves);
	}
	pb(stk_dst, stk_src, 1);
}

/*
@brief A function that executes the sequence of operations based on calculated
minimum cost.
*/
static void	do_ops(t_node **stk_src, t_node **stk_dst, t_move *move, int dir)
{
	if (dir == 0)
		do_ops_desc(stk_src, stk_dst, move);
	else
		do_ops_asc(stk_src, stk_dst, move);
}

/*
@brief A function that pushes each non-LIS node from one stack to another
in the order of descending cost.
@param stack_a The stack where you are pushing from.
@param stack_b The stack where you are pushing to.
@param move A structure that stores the minimum cost/steps for rotating
each stack.
@param dir The direction of sorting. 0 for descending, 1 for ascending.
*/
void	push_opt(t_node **stack_a, t_node **stack_b, t_move *move, int dir)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->lis == 0)
		{
			assign_index(stack_a);
			assign_index(stack_b);
			calc_cost(stack_a, stack_b, move, dir);
			do_ops(stack_a, stack_b, move, dir);
			move->size_a--;
			move->size_b++;
			tmp = *stack_a;
		}
		else
			tmp = tmp->next;
	}
}
