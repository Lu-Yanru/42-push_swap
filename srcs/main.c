/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:12:20 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/15 17:51:33 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	g_fail_at = -1;
static int	g_malloc_count = 0;

void	set_malloc_fail_at(int n)
{
	g_fail_at = n;
	g_malloc_count = 0;
}

void	*test_malloc(size_t size)
{
	if (g_fail_at >= 0 && g_malloc_count++ == g_fail_at)
		return (NULL);
	return (malloc(size));
}

/*
1. Process input
	- check validity
	- store in stack a
2. sort stack a
	- algo
	- print operations
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
	sort(&stack_a, &stack_b, size);
	t_node	*tmp;
	tmp = stack_a;
	while (tmp)
	{
		printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	printf("stackb\n");
	tmp = stack_b;
	while (tmp)
	{
		printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
