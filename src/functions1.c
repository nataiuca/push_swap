/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:01:25 by natferna          #+#    #+#             */
/*   Updated: 2025/01/22 16:32:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *stack, int size)
{
	int	min;
	int	i;

	min = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Implementación de move_max_to_a
void	move_max_to_a(t_list *d)
{
	int	index;

	if (!d || d->sib <= 0)
		return;
	index = find_max_index(d);
	rotate_max_to_top(d, index);
	pa(d);
}

void	sort_three(t_list *d)
{
	if (d->sa[0] > d->sa[1] && d->sa[0] > d->sa[2])
		ra(d);
	else if (d->sa[1] > d->sa[0] && d->sa[1] > d->sa[2])
		rra(d);
	if (d->sa[0] > d->sa[1])
		sa(d);
}

void	sortnum(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->argc - 1)
	{
		j = 0;
		while (j < d->argc - i - 1)
		{
			if (d->sp[j] > d->sp[j + 1])
				swap(&d->sp[j], &d->sp[j + 1]);
			j++;
		}
		i++;
	}
}
