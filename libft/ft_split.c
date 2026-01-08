/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:36:53 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/01 13:19:35 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			i = i + ft_wordlen(s + i, c);
		}
	}
	return (count);
}

static char	*ft_strndup(char const *s, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**arr;

	i = 0;
	start = 0;
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[start])
	{
		if (s[start] == c)
			start++;
		else
		{
			arr[i] = ft_strndup(s + start, ft_wordlen(s + start, c));
			if (!arr[i])
				return (free_arr(arr, i));
			start = start + ft_wordlen(s + start, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
