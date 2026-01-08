/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:02:03 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/08 18:03:52 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that prints an error message to the standard error,
frees stack a and b, and exits with code 1.
*/
void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	/*if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);*/
	exit (1);
}

/*void	free_arr_long(long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}*/

void	free_arr_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
