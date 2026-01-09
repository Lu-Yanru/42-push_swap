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
	/*stack_a;
	stack_b;*/

	if (argc < 2)
		return (0);
	if (check_args(argc, argv, &arr) == 0)
		error_exit(arr);
	int	i = 0;
	while (i < 6)
	{
		printf("%ld\n", arr[i++]);
	}
	/*stack_b = NULL;
	store_data(stack_a, arr);
	sort(stack_a, stack_b);*/
}
