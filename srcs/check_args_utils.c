/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:20:06 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/16 17:50:20 by yanlu            ###   ########.fr       */
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
	if (!*str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count + 1);
}

/*
@brief A function that converts a string to a long number.
*/
long	ft_atol(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	if (is_sign(str[i]) != 0)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

/*
@brief A function that joins string1 and string2, frees string1 and returns
the joined string.
*/
char	*ft_join_n_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/*
@brief A function that stores the numbers in the formatted string into
an array of integers.
*/
long	*store_numbers(char *str, long *arr)
{
	int		i;
	char	**arr_str;

	i = 0;
	arr_str = ft_split(str, ' ');
	if (!arr_str)
		return (NULL);
	while (arr_str[i])
	{
		arr[i] = ft_atol(arr_str[i]);
		i++;
	}
	free_arr_str(arr_str);
	return (arr);
}
