/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:36:37 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 14:46:17 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list *d)
{
    int temp;
    int i;

    if (d->sia > 1)
    {
        temp = d->sa[0];
        i = 0;
        while (i < d->sia - 1)
        {
            d->sa[i] = d->sa[i + 1];
            i++;
        }
        d->sa[i] = temp;
    }
}

void rb(t_list *d)
{
    int temp;
    int i;

    if (d->sib > 1)
    {
        temp = d->sb[0];
        i = 0;
        while (i < d->sib - 1)
        {
            d->sb[i] = d->sb[i + 1];
            i++;
        }
        d->sb[i] = temp;
    }
}

void rr(t_list *d)
{
    ra(d);
    rb(d);
}

void rra(t_list *d)
{
    int temp;
    int i;

    if (d->sia > 1)
    {
        temp = d->sa[d->sia - 1];
        i = d->sia - 1;
        while (i > 0)
        {
            d->sa[i] = d->sa[i - 1];
            i--;
        }
        d->sa[0] = temp;
    }
}

void rrb(t_list *d)
{
    int temp;
    int i;

    if (d->sib > 1)
    {
        temp = d->sb[d->sib - 1];
        i = d->sib - 1;
        while (i > 0)
        {
            d->sb[i] = d->sb[i - 1];
            i--;
        }
        d->sb[0] = temp;
    }
}

void rrr(t_list *d)
{
    rra(d);
    rrb(d);
}
