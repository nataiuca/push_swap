/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:49:28 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 20:04:41 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int handle_sorting(t_list *data)
{
    printf("Verificando orden en la pila A (tamaño: %d): ", data->sia);
    for (int j = 0; j < data->sia; j++)
        printf("%d ", data->sa[j]);
    printf("\n");

    if (check_order(data) < 0) // Si no está ordenada
    {
        printf("Orden incorrecto, iniciando estrategia de ordenación.\n");
        return execute_sorting_strategy(data, data->argc);
    }
    printf("La pila ya está ordenada.\n");
    return (0);
}

int execute_sorting_strategy(t_list *data, int argc)
{
    if (argc == 3 || argc == 4)
    {
        printf("Usando estrategia size3.\n");
        size3(data);
    }
    else if (argc > 4 && argc <= 6)
    {
        printf("Usando estrategia size5.\n");
        size5(data);
    }
    else if (argc > 6 && argc <= 102)
    {
        printf("Usando estrategia size100.\n");
        size100(data);
    }
    else if (argc > 102)
    {
        printf("Usando estrategia size500.\n");
        size500(data);
    }
    return (0);
}

int get_index(t_list *data, int value)
{
    int i;

    i = 0;
    while (i < data->sia)
    {
        if (data->sa[i] == value)
            return (i);
        i++;
    }
    return (-1);  // Retorna -1 si el valor no se encuentra
}

// Implementación de find_max
int find_max(t_list *data)
{
    int max_value = data->sb[0]; // Asumimos que la pila B tiene al menos un elemento
    int i;

    for (i = 1; i < data->sib; i++) // Recorre todos los elementos de la pila B
    {
        if (data->sb[i] > max_value)
            max_value = data->sb[i];
    }
    return max_value; // Devuelve el valor máximo
}
