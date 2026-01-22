/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:21:00 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 14:25:53 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief	A function that puts the top node of the source stack on
the top of the destination stack.
*/
void	push(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = NULL;
	if (!(*dst))
		*dst = tmp;
	else
		add_top(dst, tmp);
}

void	pa(t_node **stack_a, t_node **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push(stack_a, stack_b);
		ft_putendl_fd("pa", 1);
		i++;
	}
}

void	pb(t_node **stack_b, t_node **stack_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		push(stack_b, stack_a);
		ft_putendl_fd("pb", 1);
		i++;
	}
}
