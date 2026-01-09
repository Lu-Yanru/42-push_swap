/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:13:08 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/09 17:48:28 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef	struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				lis;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;


/*Check validity of input*/

int		check_args(int argc, char *argv[], long **arr, int *size);
int		check_digits(char *str);
int		check_unique_n_range(long *arr, int count);
char	*build_arg_str(int argc, char *argv[]);
long	*create_number_array(char *str, int *count);
int		is_sign(char c);
int		count_numbers(char *str);
long	*store_numbers(char *str, long *arr, int count);
long	ft_atol(char *str);
char	*ft_join_n_free(char *s1, char *s2);

/*Utilities*/
void	error_exit(long *arr);
void	free_arr_str(char **arr);

#endif
