/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:58:08 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/09 19:29:34 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that creates a new node with the value equals to
the given argument.
*/
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->cost = 0;
	node->lis = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/*
@brief A function that add a new node to the top of the stack.
*/
void	add_top(t_node **stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/*
@brief A function that finds the last node in the stack.
*/
t_node	*last_node(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/*
@brief A function that add a new node to the bottom of the stack.
*/
t_node	*add_bottom(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return (NULL);
	if (!(*stack))
		*stack = new;
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

/*
@brief A function that fills stack a with the values from the long numbers array.
The first number is at the top of the stack.
*/
void	stack_init(t_node **stack_a, long *arr, int size)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < size)
	{
		new = new_node((int) arr[i]);
		add_bottom(stack_a, new);
		i++;
	}
}
