/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:20:06 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/08 18:28:41 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that check whether a character is a + or - sign.
@param c: The character to be checked.
@return 1 if the character is a + or - sign. 0 if not.
*/
int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*long	ft_atoi(char str)
{
	return (0);
}*/


/*
@brief A function that counts how many numbers there are in the already
formatted string by counting how many spaces there are and + 1.
*/
int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count + 1);
}

/*
@brief A function that stores the numbers in the formatted string into
an array of integers.
*/
int	*store_numbers(char *str, int *arr, int count)
{
	int	i;
	int	j;
	char	*arr_str;

	i = 0;
	j = 0;
	arr_str = ft_split(str, ' ');
	while (i < count)
	{
		arr[i] = str[];
		i++;
	}
	return (arr);
}
