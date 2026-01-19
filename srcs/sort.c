/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 08:51:06 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/19 19:55:05 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that checks whether a stack is sorted or not.
@param stack The stack to be checked.
@return 1 if the stack is sorted. 0 if not.
*/
static int	check_sorted(t_node *stack)
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
static void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first < third && third < second)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (second < first && first < third)
		sa(stack, 1);
	else if (third < first && first < second)
		rra(stack, 1);
	else if (second < third && third < first)
		ra(stack, 1);
	else if (third < second && second < first)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
}

/*
@brief A function that rotates the smallest number to the top of the stack.
*/
static void	rotate_to_ascend(t_node **stack, int size)
{
	int	min_ind;

	min_ind = get_smallest_index(*stack);
	if (min_ind <= size / 2)
		ra(stack, min_ind);
	else
		rra(stack, size - min_ind);
}

/*
@brief A function that sorts stack a with a size larger than 3
with the help of stack b. It uses the algorithm described in
README.md.
*/
static void	sort_big(t_node **stack_a, t_node **stack_b, int size)
{
	t_move	move;
	int		tmp;
	int		lis_size;

	move.size_a = size;
	move.size_b = 0;
	assign_index(stack_a);
	lis_size = find_lis(stack_a, size);
	/*t_node	*tmpn;
	tmpn = *stack_a;
	printf("lis\n");
	printf("lis_size: %i\n", lis_size);
	while (tmpn)
	{
		if (tmpn->lis == 1)
			printf("%i\n", tmpn->value);
		tmpn = tmpn->next;
	}*/
	push_opt(stack_a, stack_b, &move, 0);
	if (lis_size < 3)
		sort_three(stack_a);
	/*tmpn = *stack_a;
	printf("stacka\n");
	while (tmpn)
	{
		printf("%i\n", tmpn->value);
		tmpn = tmpn->next;
	}
	tmpn = *stack_b;
	printf("stackb\n");
	while (tmpn)
	{
		printf("%i\n", tmpn->value);
		tmpn = tmpn->next;
	}*/
	tmp = move.size_a;
	move.size_a = move.size_b;
	move.size_b = tmp;
	push_opt(stack_b, stack_a, &move, 1);
	assign_index(stack_a);
	rotate_to_ascend(stack_a, size);
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
		ra(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b, size);
}
