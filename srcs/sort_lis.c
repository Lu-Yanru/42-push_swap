/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:54:16 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/15 18:04:31 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A funtion that initializes the tail and tail_val arrays.
@return 0 if the initializatio failed. 1 if successful.
*/
static int	init_tail_arrs(int **tail_val, t_node ***tail, int stack_size)
{
	int	i;

	*tail_val = malloc(stack_size * sizeof(int));
	if (!tail_val)
		return (0);
	*tail = malloc(stack_size * sizeof(t_node *));
	if (!tail)
	{
		free(tail_val);
		return (0);
	}
	i = 0;
	while (i < stack_size)
	{
		(*tail)[i] = NULL;
		(*tail_val)[i] = INT_MAX;
		i++;
	}
	return (1);
}

/*
@brief A function that marks LIS.
If the size of LIS is smaller than 3, mark more nodes as LIS
until there are 3 nodes marked as LIS.
*/
static void	mark_lis(t_node **tail, int lis_size)
{
	t_node	*tmp;

	tmp = *tail;
	while (tmp)
	{
		tmp->lis = 1;
		tmp = tmp->lis_prev;
	}
	tmp = *tail;
	while (lis_size < 3)
	{
		if (tmp->lis == 0)
		{
			tmp->lis = 1;
			lis_size++;
		}
		tmp = tmp->prev;
	}
}

/*
@brief A function that performs a binary search on tail_val to find
the smallest index (tail_len) where tail_val is bigger than the value
of the current node.
@param tail_val The array containing the values of all the potential LIS tails.
@param left The left most index (tail_len).
@param right The right most index (tail_len) = lis_size.
@param value The value of the current node.
@return The smallest index (tail_len) where tail_val is bigger than the value
of the current node. right + 1 if no such index exits.
@details
Find the middle index of the range.
Check whether the mid value is bigger than the value.
If so, set the result to the mid value and search the left half to see
if there is an earlier one.
If not, search right half.
Do this until the range is empty.
A binary search can be used because the tail_val array is sorted.
*/
static int	binary_search_lis(int *tail_val, int left, int right, int value)
{
	int	mid;
	int	res;

	res = right + 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (tail_val[mid] >= value)
		{
			res = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return (res);
}

/*
@brief A function that finds the longest increasing subsequence in a stack.
@param stack The stack where we find the LIS.
@param lis_size A pointer to the size of the LIS.
@param stack_size The size of the stack.
@details
- Use tmp pointer to loop through the stack.
- tail_len is the length of each increasing subsequence in the stack.
- tail is an array of pointers which points to the tail of
each increasing subsequence. Each pointer is stored at position
tail[tail_len].
- tail_value stores the value of the tail of each increasing subsequence.
Each value is stored at position tail_value[tail_len].

Loop through the stack.
Use binary search to find the smallest tail_len where tail_val[tal_len]
is bigger than tmp->value. This means that tmp->value can give a smaller tail
for an increasing subsequence of length tail_len. This makes it easier to find
a longer increasing sequence (extend the tail).
If tail_len is 1, this is the start of a new increasing subsequence,
tmp->lis_prev remains the initial value NULL.
Otherwise, set the previous LIS node of tmp to the tail[tail_len - 1].
- Time complexity: O(n log(n))
- Space complexity: O(n)

Finally, mark the nodes belonging to LIS in the stack by looping from the tail.
If the size of LIS is smaller than 3, mark more nodes as LIS
until there are 3 nodes marked as LIS.
*/
void	find_lis(t_node **stack, int *lis_size, int stack_size)
{
	t_node	*tmp;
	t_node	**tail;
	int		*tail_val;
	int		tail_len;

	if (!stack)
		return ;
	if (init_tail_arrs(&tail_val, &tail, stack_size) == 0)
		error_exit(NULL, stack, NULL);
	*lis_size = 0;
	tmp = *stack;
	while (tmp)
	{
		tail_len = binary_search_lis(tail_val, 1, *lis_size, tmp->value);
		if (tail_len > 1)
			tmp->lis_prev = tail[tail_len - 1];
		tail[tail_len] = tmp;
		tail_val[tail_len] = tmp->value;
		if (tail_len > *lis_size)
			*lis_size = tail_len;
		tmp = tmp->next;
	}
	mark_lis(&(tail[*lis_size]), *lis_size);
	free(tail_val);
	free(tail);
}
