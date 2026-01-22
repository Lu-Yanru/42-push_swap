/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:15:12 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 16:02:27 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
@brief A function that reads a character from the standard input.
*/
static int	read_char(char *c)
{
	int	bytes_rd;

	bytes_rd = read(0, c, 1);
	return (bytes_rd);
}

/*
@brief A function that joins a character to the end of a string.
*/
static char	*join_char(char *str, char c, int len)
{
	char	*res;

	res = malloc((len + 2) * sizeof(char));
	if  (!res)
	{
		if (str)
			free(str);
		return (NULL);
	}
	if (str)
	{
		ft_strcpy(res, str, len);
		free(str);
	}
	res[len] = c;
	res[len + 1] = '\0';
	return (res);
}

/*
@brief A function that reads from the standard input character by character
until it finds a newline, and joins them into a string.
@param line A pointer to the string to be create.
@return The bytes read. 0 if an error occurs or when there is
nothing left to read.
*/
int	read_line(char **line)
{
	int		bytes_rd;
	char	c;
	int		len;
	char	*res;

	res = NULL;
	len = 0;
	bytes_rd = read_char(&c);
	while (bytes_rd > 0)
	{
		if (c == '\n')
			break ;
		res = join_char(res, c, len);
		if (!res)
		{
			*line = NULL;
			return (0);
		}
		len++;
		bytes_rd = read_char(&c);
	}
	*line = res;
	return (bytes_rd);
}
