/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:40:11 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/21 17:58:39 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_swap(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		error_exit(NULL, stack_a, stack_b);
}

static void	exec_rot(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		rev_rotate(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		rev_rotate(stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		error_exit(NULL, stack_a, stack_b);
}

static void	exec_push(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(line, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "pb") == 0)
		push(stack_b, stack_a);
	else
		error_exit(NULL, stack_a, stack_b);
}

void	exec_ops(char *line, t_node **stack_a, t_node **stack_b)
{
	if (line[0] == 's')
		exec_swap(line, stack_a, stack_b);
	else if (line[0] == 'r')
		exec_rot(line, stack_a, stack_b);
	else if (line[0] == 'p')
		exec_push(line, stack_a, stack_b);
	else
		error_exit(NULL, stack_a, stack_b);
}
