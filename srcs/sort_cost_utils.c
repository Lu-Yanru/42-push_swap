/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:44 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/20 13:40:29 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function to get the index of the smallest number in a stack.
*/
int	get_smallest_index(t_node *stack)
{
	int		smallest_index;
	int		smallest;
	t_node	*tmp;

	if (!stack)
		return (0);
	smallest = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value <= smallest)
		{
			smallest = tmp->value;
			smallest_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (smallest_index);
}

/*
@brief A function to get the index of the biggest number in a stack.
*/
int	get_biggest_index(t_node *stack)
{
	int		biggest_index;
	int		biggest;
	t_node	*tmp;

	if (!stack)
		return (0);
	biggest = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value >= biggest)
		{
			biggest = tmp->value;
			biggest_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (biggest_index);
}

/*
@brief A function that finds the correct position for putting a node
in ascending in a stack,
i.e. the index of the cloest bigger number in stack a.
@param stack A pointer to stack to be inserted.
@param value The of the node to be moved.
@return The index of the target position.
@details
If the stack is empty, the target index is simply 0.
Loop through stack a.
Check if a number is bigger than the to-be-moved value,
store it in tmp_val.
Continue checking to see if there is a number smaller than tmp_val but still
bigger than the to-be-moved value. Keep its index.
If tmp_val remains unchanged from the inital value, it means that all values
in stack a are smaller than the to-be-moved value. In this case,
the target index is the index of the smallest number in stack a.
*/
static int	find_target_ascend(t_node *stack, int value)
{
	t_node	*tmp;
	long	tmp_val;
	int		target_index;

	if (!stack)
		return (0);
	tmp = stack;
	tmp_val = (long) INT_MAX + 1;
	while (tmp)
	{
		if (tmp->value < tmp_val && tmp->value > value)
		{
			tmp_val = tmp->value;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp_val == (long) INT_MAX + 1)
		target_index = get_smallest_index(stack);
	return (target_index);
}

/*
@brief A function that finds the correct position for putting a node
in descending order in a stack,
i.e. the index of the cloest smaller number in stack b.
@param stack A pointer to stack to be inserted.
@param value The of the node to be moved.
@return The index of the target position.
@details
If the stack is empty, the target index is simply 0.
Loop through stack b.
Check if a number is smaller than the to-be-moved value,
store it in tmp_val.
Continue checking to see if there is a number bigger than tmp_val but still
smaller than the to-be-moved value. Keep its index.
If tmp_val remains unchanged from the inital value, it means that all values
in stack b are bigger than the to-be-moved value. In this case,
the target index is the index of the biggest number in stack b.
*/
static int	find_target_descend(t_node *stack, int value)
{
	t_node	*tmp;
	long	tmp_val;
	int		target_index;

	if (!stack)
		return (0);
	tmp = stack;
	tmp_val = (long) INT_MIN - 1;
	while (tmp)
	{
		if (tmp->value > tmp_val && tmp->value < value)
		{
			tmp_val = tmp->value;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp_val == (long) INT_MIN - 1)
		target_index = get_biggest_index(stack);
	return (target_index);
}

/*
@brief A function to find the target index in the destination stack
for the current value for direction ascending (1) or descending (0).
*/
int	find_target(t_node *stack, int value, int direction)
{
	int	target_index;

	if (!stack)
		return (0);
	if (direction != 0)
		target_index = find_target_ascend(stack, value);
	else
		target_index = find_target_descend(stack, value);
	return (target_index);
}
