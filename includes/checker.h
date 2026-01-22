/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:34:20 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/22 13:46:51 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "push_swap.h"

/* Read line */
int		read_line(char **line);

/* Exec ops */
void	exec_ops(char *line, t_node **stack_a, t_node **stack_b);

/* Untilities */
void	ft_strcpy(char *dst, char *src, int len);
int		ft_strcmp(char *s1, char *s2);

#endif
