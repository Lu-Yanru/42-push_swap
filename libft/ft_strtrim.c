/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:10:36 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/04 16:43:13 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	size;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_isset(s1[start], set) != 0)
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_isset(s1[end], set) != 0)
		end--;
	size = end - start + 2;
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, size);
	return (res);
}
