/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:28:12 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/14 19:19:35 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that calculates the cost for moving a node to the correct position.
cost_a, cost_b, cost_shared: rotate if positive. reverse rotate if negative.
*/
void	calc_cost(t_node **stack_a, t_node **stack_b, t_move *move, int direction)
{
	t_node	*tmp;
	int		min_cost;
	t_move	tmp_move;

	min_cost = INT_MAX;
	tmp = *stack_a;
	tmp_move.size_a = move->size_a;
	tmp_move.size_b = move->size_b;
	tmp_move.index = tmp->index;
	while (tmp && min_cost > tmp_move.index + 1 && min_cost > tmp_move.size_a - tmp_move.index - 1)
	{
		tmp_move.index = tmp->index;
		if (direction != 0)
			tmp_move.target_index = find_target_ascend(*stack_a, tmp->value);
		else
			tmp_move.target_index = find_target_descend(*stack_b, tmp->value);
		if (tmp_move.index < (tmp_move.size_a) / 2)
			tmp_move.cost_a = tmp_move.index;
		else
			tmp_move.cost_a = -(tmp_move.size_a - tmp_move.index);
		if (tmp_move.target_index < (tmp_move.size_b) / 2)
			tmp_move.cost_b = tmp_move.target_index;
		else
			tmp_move.cost_b = -(tmp_move.size_b - tmp_move.target_index);
		if (tmp_move.cost_a < 0 && tmp_move.cost_b < 0)
		{
			if (ft_abs(tmp_move.cost_a) >= ft_abs(tmp_move.cost_b))
			{
				tmp_move.cost_shared = tmp_move.cost_b;
				tmp_move.cost_all = ft_abs(tmp_move.cost_a);
			}
			else
			{
				tmp_move.cost_shared = tmp_move.cost_a;
				tmp_move.cost_all = ft_abs(tmp_move.cost_b);
			}
		}
		else if (tmp_move.cost_a >= 0 && tmp_move.cost_b >= 0)
		{
			if (tmp_move.cost_a >= tmp_move.cost_b)
			{
				tmp_move.cost_shared = tmp_move.cost_b;
				tmp_move.cost_all = tmp_move.cost_a;
			}
			else
			{
				tmp_move.cost_shared = tmp_move.cost_a;
				tmp_move.cost_all = tmp_move.cost_b;
			}
		}
		else
		{
			tmp_move.cost_shared = 0;
			tmp_move.cost_all = ft_abs(tmp_move.cost_a) + ft_abs(tmp_move.cost_b);
		}
		if (tmp_move.cost_all < min_cost)
		{
			min_cost = tmp_move.cost_all;
			move->index = tmp_move.index;
			move->target_index = tmp_move.target_index;
			move->cost_a = tmp_move.cost_a;
			move->cost_b = tmp_move.cost_b;
			move->cost_all = tmp_move.cost_all;
			move->cost_shared = tmp_move.cost_shared;
		}
		tmp = tmp->next;
	}
}
