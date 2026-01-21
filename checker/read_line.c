/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:15:12 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/21 18:06:27 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
@brief A function that reads a character from the standard input.
*/
static int	read_char(char *c)
{
	int	bytes_rd;

	bytes_rd = read(0, c, 1);
	return (bytes_rd);
}

static char	*join_char(char **line, char *c, int len)
{
	char	*res;

	if (!len)
		return (c);
	res = malloc((len + 2) * sizeof(char));
	if  (!res)
	{
		free(*line);
		return (NULL);
	}
	ft_strcpy(res, *line, len);
	res[len] = *c;
	res[len + 1] = '\0';
	free(*line);
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

	len = 0;
	bytes_rd = read_char(&c);
	while (bytes_rd > 0)
	{
		if (c == '\n')
			break ;
		*line = join_char(line, &c, len);
		if (!*line)
			return (0);
		len++;
		bytes_rd = read_char(&c);
	}
	return (bytes_rd);
}
