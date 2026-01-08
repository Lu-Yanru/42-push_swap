/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:23:14 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/08 18:27:01 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that checks whether a string contains
only whole numbers (optionally preceded by +/- sign) separated by a space.
@param[in] str The string to be checked.
@return 1 if the string contains only numbers separated by one space. 0 if not.
*/
int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_sign(str[i]) && str[i + 1] != '\0' && str[i + 1] != ' ')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == ' ' && i != 0 && str[i + 1] != ' ' && str[i + 1] != '\0')
			i++;
		else
			break;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

/*
@brief A function that checks whether the
*/
int	check_unique_and_range(long *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		while (j < count)
		{
			if (i != j && arr[i] == arr[j])
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
@brief A function to check the validity of the input arguments.
@param[in] argc The number of arguments given to the program.
@param[in] argv The arguments given to the program.
@return 1 if the arguments are valid. 0 if not.

@details
The following conditions has to be met for the argument to be valid:
- The input can only include digits and '+' and '-' signs, separated by spaces.
- The input numbers has to be unique.
- The input numbers need to be within the range of an integer.

The function also prints "Error\n" to the standard error if the input arguments
are not valid.
*/
int	check_args(int argc, char *argv[])
{
	int			i;
	char		*str;
	long		*arr;
	int			count;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (0);
	while (i < argc)
	{
		if (check_digits(argv[i]) == 0)
		{
			free(str);
			return (0);
		}
		if (str[0] != '\0')
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (0);
		i++;
	}
	count = count_numbers(str);
	arr = malloc(count * sizeof(long));
	if (!arr)
	{
		free(str);
		return (0);
	}
	arr = store_numbers(str, arr, count);
	if (!arr)
	{
		free(str);
		return (0);
	}
	if (check_unique_and_range(arr, count) == 0)
	{
		free(str);
		free(arr);
		return (0);
	}
	free(str);
	free(arr);
	return (1);
}
