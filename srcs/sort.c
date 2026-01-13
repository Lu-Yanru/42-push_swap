/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 08:51:06 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/11 18:56:59 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

/*
@brief A function that checks whether a stack is sorted or not.
@param stack The stack to be checked.
@return 1 if the stack is sorted. 0 if not.
*/
int	check_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
@brief A function that sorts a stack with 3 elements in 2 or less steps.
*/
void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first < third && third < second)
	{
		rra(stack);
		sa(stack);
	}
	else if (second < first && first < third)
		sa(stack);
	else if (third < first && first < second)
		rra(stack);
	else if (second < third && third < first)
		ra(stack);
	else if (third < second && second < first)
	{
		ra(stack);
		sa(stack);
	}
}

/*
@brief A function that sorts stack a with a size larger than 3
with the help of stack b. It uses the algorithm described in
README.md.
*/
void	sort_big(t_node **stack_a, t_node **stack_b, int size)
{
	int	lis_size;

	find_lis(stack_a, &lis_size, size);
	/*
	push_non_lis(stack_a, stack_b);
	if (lis_size < 3)
		sort_three(stack_a);
	push_back(stack_a, stack_b);
	rotate_to_ascend(stack_a);*/
	*stack_b = NULL;
	t_node	*tmp;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->lis != 0)
			printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	printf("size: %i\n", lis_size);
}

/*
@brief A function that sorts stack a with the help of stack b.
@details
If stack a is already sorted, do nothing.
If the size of stack a is 2, ra.
If the size of stack a is 3, use sort_three.
Otherwise, use the algorithm sort_big.
*/
void	sort(t_node **stack_a, t_node **stack_b, int size)
{
	if (size <= 1 || check_sorted(*stack_a) != 0)
		return ;
	if (size == 2)
		ra(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b, size);
}
