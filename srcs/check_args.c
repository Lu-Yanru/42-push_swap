/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:23:14 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/20 11:46:18 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that checks whether a string contains
only whole numbers (optionally preceded by +/- sign) separated by a space.
@param str The string to be checked.
@return 1 if the string contains only numbers separated by one space. 0 if not.
*/
static int	check_digits(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (is_sign(str[i]) && str[i + 1] != '\0' && str[i + 1] != ' ')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == ' ' && i != 0 && str[i + 1] != ' ' && str[i + 1] != '\0')
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

/*
@brief A function that checks whether the each number in an array of long numbers
are unque and also within the range of an integer.
*/
static int	check_unique_n_range(long *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
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
@brief A function that checks if each command line argument only contains
numbers, and if so, join them into a big string.
*/
static char	*build_arg_str(int argc, char *argv[])
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (i < argc)
	{
		if (check_digits(argv[i]) == 0)
		{
			free(str);
			return (NULL);
		}
		if (str[0] != '\0' && argv[i][0] != '\0')
			str = ft_join_n_free(str, " ");
		str = ft_join_n_free(str, argv[i]);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

/*
@brief A function that creates an array of long numbers based on a string
separated by spaces. It also calculates the size of the array.
@param str A formatted string containing the numbers to be converted
separated by spaces.
@param count A pointer to the size of the array.
@return The array of long numbers.
*/
static long	*create_number_array(char *str, int *count)
{
	long	*arr;

	*count = count_numbers(str);
	arr = malloc((*count) * sizeof(long));
	if (!arr)
		return (NULL);
	arr = store_numbers(str, arr);
	return (arr);
}

/*
@brief A function to check the validity of the input arguments.
@param argc The number of arguments given to the program.
@param argv The arguments given to the program.
@return 1 if the arguments are valid. 0 if not.

@details
The following conditions has to be met for the argument to be valid:
- The input can only include digits and '+' and '-' signs, separated by spaces.
- The input numbers has to be unique.
- The input numbers need to be within the range of an integer.

If valid, the function also converts in command line input into an array of long
numbers and calculates its size (how many numbers).
*/
int	check_args(int argc, char *argv[], long **arr, int *size)
{
	char	*str;

	str = build_arg_str(argc, argv);
	if (!str)
		return (0);
	*arr = create_number_array(str, size);
	if (!(*arr))
	{
		free(str);
		return (0);
	}
	if (check_unique_n_range(*arr, *size) == 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
