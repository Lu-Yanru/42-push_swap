/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:26:58 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/11 08:35:07 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that free one node in the linked list.
*/
void	free_node(t_node *node)
{
	if (!node)
		return ;
	node->value = 0;
	free(node);
}

/*
@brief A function that frees the whole stack.
*/
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free_node(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
