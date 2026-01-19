/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanlu <yanlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:54:16 by yanlu             #+#    #+#             */
/*   Updated: 2026/01/19 19:47:42 by yanlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief A function that frees the elements in t_lis.
*/
static void	free_t_lis(t_lis *lis)
{
	free(lis->tail);
	free(lis->tail_val);
	lis->lis_size = 0;
	lis->tail_len = 0;
}

static void	reset_lis_nodes(t_node **stack)
{
	t_node	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp->lis_prev = NULL;
		tmp = tmp->next;
	}
}

/*
@brief A funtion that initializes the tail and tail_val arrays.
@return 0 if the initializatio failed. 1 if successful.
*/
static int	init_tail_arrs(t_lis *lis, int stack_size)
{
	int	i;

	lis->lis_size= 0;
	lis->tail_val = malloc((stack_size + 1) * sizeof(int));
	lis->tail = malloc((stack_size + 1) * sizeof(t_node *));
	if (!(lis->tail_val) || !(lis->tail))
	{
		free_t_lis(lis);
		return (0);
	}
	i = 0;
	while (i <= stack_size)
	{
		(lis->tail)[i] = NULL;
		(lis->tail_val)[i] = INT_MAX;
		i++;
	}
	(lis->tail_val)[0] = INT_MIN;
	return (1);
}

/*
@brief A function that marks LIS.
If the size of LIS is smaller than 3, mark more nodes as LIS
until there are 3 nodes marked as LIS.
*/
static void	mark_lis(t_node **tail, int lis_size, t_node **stack)
{
	t_node	*tmp;

	tmp = *tail;
	while (tmp)
	{
		tmp->lis = 1;
		tmp = tmp->lis_prev;
	}
	tmp = *stack;
	while (lis_size < 3)
	{
		if (tmp->lis == 0)
		{
			tmp->lis = 1;
			lis_size++;
		}
		tmp = tmp->next;
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
@param lis_size A pointer to the size of the LIS
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
static void	lis_from_start(t_node *start, t_lis *lis, int stack_size, t_node **stack)
{
	t_node	*tmp;
	int		i;

	if (!start || !*stack)
		return ;
	if (init_tail_arrs(lis, stack_size) == 0)
		return ;
	tmp = start;
	i = 0;
	while (i < stack_size)
	{
		lis->tail_len = binary_search_lis(lis->tail_val, 1, lis->lis_size, tmp->value);
		if (lis->tail_len == 1)
			tmp->lis_prev = NULL;
		else
			tmp->lis_prev = lis->tail[lis->tail_len - 1];
		lis->tail[lis->tail_len] = tmp;
		lis->tail_val[lis->tail_len] = tmp->value;
		if (lis->tail_len > lis->lis_size)
			lis->lis_size = lis->tail_len;
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = *stack;
		i++;
	}
}

/*
@brief A function that counts how many numbers are greater than the current value
in a circular way.
*/
static int	count_greater(t_node *start, int stack_size, t_node **stack)
{
	int		count;
	t_node	*tmp;
	int		i;

	count = 0;
	i = 1;
	if (start->next)
		tmp = start->next;
	else
		tmp = *stack;
	while (i < stack_size)
	{
		if (tmp->value > start->value)
			count++;
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = *stack;
		i++;
	}
	return (count + 1);
}

int	find_lis(t_node **stack, int stack_size)
{
	t_node	*tmp;
	t_node	*best_start;
	t_lis	lis;
	int		best_len;
	
	best_start = NULL;
	best_len = 0;
	tmp = *stack;
	while (tmp)
	{
		if (count_greater(tmp, stack_size, stack) > best_len)
		{
			reset_lis_nodes(stack);
			lis_from_start(tmp, &lis, stack_size, stack);
			if (lis.lis_size > best_len)
			{
				best_len = lis.lis_size;
				best_start = tmp;
			}
			free_t_lis(&lis);
		}
		tmp = tmp->next;
	}
	reset_lis_nodes(stack);
	lis_from_start(best_start, &lis, stack_size, stack);
	mark_lis(&lis.tail[best_len], best_len, stack);
	free_t_lis(&lis);
	return (best_len);
}
