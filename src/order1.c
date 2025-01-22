/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:57:03 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 13:58:24 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ordernums(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->sia - 1)
	{
		if (d->sa[i] > d->sa[i + 1])
		{
			sa(d);
			i = 0;
		}
		else
			i++;
	}
}

void	ordernums_sb(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->sib - 1)
	{
		if (d->sb[i] < d->sb[i + 1])
		{
			sb(d);
			i = 0;
		}
		else
			i++;
	}
}

void	ordernums_sb_rotate(t_list *d)
{
	while (d->sib > 0)
	{
		if (d->sb[0] == d->lsp)
		{
			pa(d);
			d->lsp++;
		}
		else
			rb(d);
	}
}

void	ordernums_peq(t_list *d)
{
	int	i;
	int	limit;

	i = 0;
	limit = d->sip / d->cont;
	while (i < limit && d->sia > 0)
	{
		if (d->sa[0] <= d->percentage)
		{
			pb(d);
			i++;
		}
		else
			ra(d);
	}
}

void	ordernums_peq2(t_list *d)
{
	int	median;

	median = d->sip / 2;
	while (d->sia > median)
	{
		if (d->sa[0] <= median)
			pb(d);
		else
			ra(d);
	}
}
