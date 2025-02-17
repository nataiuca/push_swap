/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:02:24 by natferna          #+#    #+#             */
/*   Updated: 2025/02/16 22:37:28 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	map_stack(t_stack *stack)
{
	int		*array;
	int		i;
	t_node	*current;

	array = stack2array(stack);
	quicksort(array, stack->size);
	if (array)
	{
		current = stack->top;
		while (current)
		{
			i = 0;
			while (i < stack->size)
			{
				if (current->value == array[i])
				{
					current->index = i;
					break ;
				}
				i++;
			}
			current = current->next;
		}
	}
	free(array);
}

int	max_index(t_stack *stack)
{
	int		max;
	t_node	*current;

	max = 0;
	if (stack->size > 0)
	{
		current = stack->top;
		max = current->index;
		while (current->next)
		{
			current = current->next;
			if (current->index > max)
				max = current->index;
		}
	}
	return (max);
}

int	min_index(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	mean_index(t_stack *stack)
{
	int		sum;
	int		count;
	t_node	*current;

	current = stack->top;
	sum = 0;
	count = 0;
	while (current)
	{
		sum += current->index;
		count++;
		current = current->next;
	}
	return (sum / count);
}

int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}
