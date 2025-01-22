/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:58:33 by natferna          #+#    #+#             */
/*   Updated: 2025/01/22 16:33:40 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordernums_peq3(t_list *d, int i)
{
	int	limit;

	limit = d->sip / d->cont;
	while (i < limit && d->sib > 0)
	{
		if (d->sb[0] >= d->percentage)
		{
			pa(d);
			i++;
		}
		else
			rb(d);
	}
}

void	ordernums_peq_sb(t_list *d)
{
	while (d->sib > 0)
	{
		if (d->sb[0] == d->amax)
		{
			pa(d);
			d->amax--;
		}
		else
			rb(d);
	}
}

int	find_max_index(t_list *d)
{
	int	max;
	int	index;
	int	i;

	max = d->sb[0];
	index = 0;
	i = 1;
	while (i < d->sib)
	{
		if (d->sb[i] > max)
		{
			max = d->sb[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	rotate_max_to_top(t_list *d, int index)
{
	while (index != 0)
	{
		if (index <= d->sib / 2)
		{
			rb(d);
			index--;
		}
		else
		{
			rrb(d);
			index = (index + 1) % d->sib;
		}
	}
}
