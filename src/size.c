/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:51:48 by natferna          #+#    #+#             */
/*   Updated: 2025/01/22 16:29:37 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void size3(t_list *d)
{
    if (d->sa[0] > d->sa[1] && d->sa[0] > d->sa[2])
        ra(d); // Si el mayor está en la posición 0, mueve el mayor a la posición final.
    if (d->sa[1] > d->sa[0] && d->sa[1] > d->sa[2])
        rra(d); // Si el mayor está en la posición 1, mueve el mayor a la posición final.
    if (d->sa[0] > d->sa[1])
        sa(d); // Si el primer elemento es mayor que el segundo, intercámbialos.
}

void size5(t_list *d)
{
    int min;

    printf("Ordenando 5 elementos...\n");
    while (d->sia > 3)
    {
        min = find_min(d->sa, d->sia);
        if (d->sa[0] == min)
            pb(d); // Mueve el mínimo a la pila B.
        else
            ra(d); // Rota para que el mínimo quede en la parte superior.
    }
    if (!is_sorted(d->sa, d->sia))
        sort_three(d); // Ordena los 3 elementos restantes en la pila A.
    while (d->sib > 0)
        pa(d); // Mueve los elementos de la pila B de vuelta a A.
    printf("Estado después de ordenar 5 elementos: ");
    print_stacks(d);
}

void push_chunks_to_b(t_list *d, int chunk_size, int limit)
{
    while (d->sia > 0)
    {
        if (d->sa[0] <= limit)
        {
            pb(d);
            if (d->sb[0] <= limit - (chunk_size / 2))
                rb(d);
        }
        else
            ra(d);
        if (d->sib >= limit)
            limit += chunk_size;
    }
}

void	size100(t_list *d)
{
	int	chunk_size;
	int	limit;

	if (!d || d->sia <= 0)
		return;
	chunk_size = (d->sia + 4) / 5; // Redondea hacia arriba para dividir en 5 partes
	limit = chunk_size;

	while (d->sia > 0)
	{
		if (d->sa[0] <= limit)
		{
			pb(d);
			if (d->sib > 1 && d->sb[0] <= limit - (chunk_size / 2))
				rb(d);
		}
		else
			ra(d);
		if (d->sib >= limit)
			limit += chunk_size;
	}
	while (d->sib > 0)
	{
		move_max_to_a(d); // Mueve el elemento más grande de B a A
	}
}

void size500(t_list *d)
{
    int chunk_size;
    int limit;

    chunk_size = d->sia / 10;
    limit = chunk_size;
    while (d->sia > 0)
    {
        if (d->sa[0] <= limit)
        {
            pb(d);
            if (d->sb[0] <= limit) // Verifica el límite y decide si hacer rb.
                rb(d);
        }
        else
            ra(d);
        if (d->sib >= limit)
            limit += chunk_size;
    }
    while (d->sib > 0)
        move_max_to_a(d);
}
