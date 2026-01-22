/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:28:12 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 16:27:27 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that calculates the cost for moving one node to the top
of the stack.
@param index The index of the node to be moved.
@param size The size of the stack.
@return The cost for moving the node at to the top of the stack.
Positive if rotate. Negative if reverse rotate.
*/
static int	calc_cost_one_node(int index, int size)
{
	int	cost;

	if (size <= 1)
		return (0);
	if (index <= (size / 2))
		cost = index;
	else
		cost = -(size - index);
	return (cost);
}

/*
@brief A function that calculates the number of steps where both stacks
can be rotated in one direction using rr or rrr.
Positive if rotate. Negative if reverse rotate.
*/
static int	calc_cost_shared(int cost_a, int cost_b)
{
	int	cost_shared;

	if (ft_abs(cost_a) < ft_abs(cost_b))
		cost_shared = cost_a;
	else
		cost_shared = cost_b;
	if ((cost_a <= 0 && cost_b <= 0) || (cost_a >= 0 && cost_b >= 0))
		return (cost_shared);
	else
		return (0);
}

/*
@brief A function that calculated the total cost for moving one node to
its correct position in the other stack.
Always positive.
*/
static int	calc_cost_all(int cost_a, int cost_b)
{
	int	cost_all;

	if (ft_abs(cost_a) > ft_abs(cost_b))
		cost_all = ft_abs(cost_a);
	else
		cost_all = ft_abs(cost_b);
	if ((cost_a <= 0 && cost_b <= 0) || (cost_a >= 0 && cost_b >= 0))
		return (cost_all);
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

static void	update_min_cost(t_move *move, t_move *tmp_mv)
{
	move->target_index = tmp_mv->target_index;
	move->cost_a = tmp_mv->cost_a;
	move->cost_b = tmp_mv->cost_b;
	move->cost_all = tmp_mv->cost_all;
	move->cost_shared = tmp_mv->cost_shared;
}

/*
@brief A function that calculates the minimum cost for moving a node to
the correct position.
*/
void	calc_cost(t_node **stack_a, t_node **stack_b, t_move *move, int dir)
{
	t_node	*tmp;
	t_move	tmp_mv;

	move->cost_all = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if ((dir == 0 && tmp->lis != 0) || (move->cost_all <= tmp->index
				&& move->cost_all <= move->size_a - tmp->index))
		{
			tmp = tmp->next;
			continue ;
		}
		tmp_mv.target_index = find_target(*stack_b, tmp->value, dir);
		tmp_mv.cost_a = calc_cost_one_node(tmp->index, move->size_a);
		tmp_mv.cost_b = calc_cost_one_node(tmp_mv.target_index, move->size_b);
		tmp_mv.cost_shared = calc_cost_shared(tmp_mv.cost_a, tmp_mv.cost_b);
		tmp_mv.cost_all = calc_cost_all(tmp_mv.cost_a, tmp_mv.cost_b);
		if (tmp_mv.cost_all < move->cost_all)
			update_min_cost(move, &tmp_mv);
		tmp = tmp->next;
	}
}
