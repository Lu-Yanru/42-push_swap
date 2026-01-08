/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:13:08 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/08 18:26:48 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

#include "libft/libft.h"

/*Check validity of input*/

int		check_args(int argc, char *argv[]);
int		is_sign(char c);
int		count_numbers(char *str);
int		*store_numbers(char *str, int *arr, int count);

/*Utilities*/
void	error_exit(void);
void	free_int_arr(int *arr, int size);

#endif