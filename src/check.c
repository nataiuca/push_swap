/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:47:56 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:47 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int check_args(char **args, int argc)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (check_num(args[i + 1]) < 0 || args[i + 1][0] == '\0')
            return (-1);
        i++;
    }
    return (0);
}

int check_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' && str[i + 1] != '\0')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (0);
}

int check_order(t_list *data)
{
    int i;

    i = 0;
    printf("Verificando el orden en la pila A (tamaño: %d)...\n", data->sia);
    while (i < data->sia - 1)
    {
        printf("Comparando %d con %d\n", data->sa[i], data->sa[i + 1]);
        if (data->sa[i] > data->sa[i + 1])
        {
            printf("Orden incorrecto encontrado en índice %d\n", i);
            return (-1); // Desordenado
        }
        i++;
    }
    printf("Pila A está ordenada.\n");
    return (0); // Ordenado
}

int check_same_nums(t_list *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->sia)
    {
        j = i + 1;
        while (j < data->sia)
        {
            if (data->sa[i] == data->sa[j])
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

void	changenum(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->argc)
	{
		j = 0;
		while (j < d->argc)
		{
			if (d->sa[i] == d->sp[j])
			{
				d->sa[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
