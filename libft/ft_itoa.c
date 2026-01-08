/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:28:45 by yanlu             #+#    #+#             */
/*   Updated: 2025/12/01 14:19:26 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_size(int n)
{
	int	len;

	if (n == 0)
		return (2);
	if (n < 0)
		len = 2;
	else
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	nlong;

	nlong = n;
	size = calc_size(n);
	res = malloc(size * sizeof(char));
	if (!res)
		return (NULL);
	res[size - 1] = '\0';
	size = size - 2;
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		nlong = -nlong;
	}
	while (nlong != 0)
	{
		res[size] = nlong % 10 + '0';
		nlong = nlong / 10;
		size--;
	}
	return (res);
}
