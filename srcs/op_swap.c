/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:54:23 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/21 17:42:13 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that swaps the top 2 nodes in a stack.
*/
void	swap(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

void	sa(t_node **stack_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		swap(stack_a);
		ft_putendl_fd("sa", 1);
		i++;
	}
}

void	sb(t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		swap(stack_b);
		ft_putendl_fd("sb", 1);
		i++;
	}
}

void	ss(t_node **stack_a, t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		swap(stack_a);
		swap(stack_b);
		ft_putendl_fd("ss", 1);
		i++;
	}
}
