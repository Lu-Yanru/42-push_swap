/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:12:20 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/08 15:29:10 by yanlu            ###   ########.fr       */
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
	/*stack_a;
	stack_b;*/

	if (argc < 2)
		return (0);
	arr = NULL;
	if (check_args(argc, argv, &arr, &size) == 0)
		error_exit(arr);
	int	i = 0;
	printf("%d\n", size);
	while (i < 6)
	{
		printf("%ld\n", arr[i++]);
	}
	free(arr);
	/*stack_b = NULL;
	store_data(stack_a, arr, size);
	sort(stack_a, stack_b);*/
}
