/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:42:03 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/21 17:38:23 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function to rotate a stack forward. Top node becomes bottom node.
*/
void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = last_node(*stack);
	tmp = (*stack)->next;
	last->next = *stack;
	(*stack)->prev = last;
	tmp->prev = NULL;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	ra(t_node **stack_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate(stack_a);
		ft_putendl_fd("ra", 1);
		i++;
	}
}

void	rb(t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate(stack_b);
		ft_putendl_fd("rb", 1);
		i++;
	}
}

void	rr(t_node **stack_a, t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_putendl_fd("rr", 1);
		i++;
	}
}
