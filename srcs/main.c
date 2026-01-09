/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:12:20 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/09 17:51:22 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
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
	//t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	arr = NULL;
	if (check_args(argc, argv, &arr, &size) == 0)
		error_exit(arr);
	free(arr);
	stack_b = NULL;
	//store_data(stack_a, arr, size);
	free(arr);
	/*sort(stack_a, stack_b);*/
}
