/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:05:31 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 14:27:19 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function to rotate a stack backwards. The bottom becomes the top.
*/
void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = last_node(*stack);
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **stack_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rev_rotate(stack_a);
		ft_putendl_fd("rra", 1);
		i++;
	}
}

void	rrb(t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rev_rotate(stack_b);
		ft_putendl_fd("rrb", 1);
		i++;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		ft_putendl_fd("rrr", 1);
		i++;
	}
}
