/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:31 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 19:24:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sa(t_list *d)
{
    int temp;

    if (d->sia > 1)
    {
        temp = d->sa[0];
        d->sa[0] = d->sa[1];
        d->sa[1] = temp;
    }
}

void sb(t_list *d)
{
    int temp;

    if (d->sib > 1)
    {
        temp = d->sb[0];
        d->sb[0] = d->sb[1];
        d->sb[1] = temp;
    }
}

void ss(t_list *d)
{
    sa(d);
    sb(d);
}

void pa(t_list *d)
{
    int i;

    if (d->sib > 0)
    {
        i = d->sia;
        while (i > 0)
        {
            d->sa[i] = d->sa[i - 1];
            i--;
        }
        d->sa[0] = d->sb[0];
        i = 0;
        while (i < d->sib - 1)
        {
            d->sb[i] = d->sb[i + 1];
            i++;
        }
        d->sib--;
        d->sia++;
    }
}

void pb(t_list *d)
{
    int i;

    if (d->sia > 0)
    {
        i = d->sib;
        while (i > 0)
        {
            d->sb[i] = d->sb[i - 1];
            i--;
        }
        d->sb[0] = d->sa[0];
        i = 0;
        while (i < d->sia - 1)
        {
            d->sa[i] = d->sa[i + 1];
            i++;
        }
        d->sia--;
        d->sib++;
		printf("Después de pb: Pila A (tamaño: %d): ", d->sia);
    for (int j = 0; j < d->sia; j++)
        printf("%d ", d->sa[j]);
    printf("\n");
    printf("Después de pb: Pila B (tamaño: %d): ", d->sib);
    for (int j = 0; j < d->sib; j++)
        printf("%d ", d->sb[j]);
    printf("\n");
    }
}
