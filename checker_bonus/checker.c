/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:21:57 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 15:58:49 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	process_instructions(t_node **stack_a, t_node **stack_b)
{
	char	*line;
	int		bytes_rd;

	while (1)
	{
		bytes_rd = read_line(&line);
		if (bytes_rd < 0)
		{
			if (line)
				free(line);
			return (0);
		}
		if (bytes_rd == 0)
			break ;
		if (!line)
			return (0);
		exec_ops(line, stack_a, stack_b);
		free(line);
	}                                                                                                       
	return (1);
}

static void	print_res(t_node *stack_a, t_node *stack_b)
{
	if (check_sorted(stack_a) != 0 && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

/*
1. Check if arguments are valid. If not, display "error".
2. Store arguments in stack a.
3. Read output from push_swap from the standard input.
4. Execute commands on stack a and stack b line by line.
5. Check if stack a is sorted and stack b is empty. Display "OK" or "KO".
*/
int	main(int argc, char *argv[])
{
	long	*arr;
	int		size;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	arr = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (check_args(argc, argv, &arr, &size) == 0)
		error_exit(arr, &stack_a, &stack_b);
	stack_init(&stack_a, arr, size);
	free(arr);
	if (process_instructions(&stack_a, &stack_b) == 0)
		error_exit(NULL, &stack_a, &stack_b);
	print_res(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
