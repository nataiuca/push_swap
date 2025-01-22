/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:43:15 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 19:56:11 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Función para imprimir el estado de la pila A y B
void print_stacks(t_list *d)
{
    printf("Pila A (tamaño: %d): ", d->sia);
    for (int i = 0; i < d->sia; i++)
        printf("%d ", d->sa[i]);
    printf("\nPila B (tamaño: %d): ", d->sib);
    for (int i = 0; i < d->sib; i++)
        printf("%d ", d->sb[i]);
    printf("\n");
}

// Función para imprimir los mensajes de depuración
void print_debug_message(const char *message)
{
    printf("DEBUG: %s\n", message);
}

int main(int argc, char **argv)
{
    t_list *data;

    if (argc < 2)
        return (0);

    // Inicialización de la estructura de datos
    data = malloc(sizeof(t_list));
    if (!data)
        return (1);

    print_debug_message("Estructura de datos 'data' creada.");

    // Verificación de los argumentos
    if (check_args(argv, argc - 1) < 0)
    {
        print_debug_message("Argumentos inválidos.");
        free(data);
        return (1);
    }
    print_debug_message("Argumentos validados.");

    // Inicialización de las pilas
    if (init_stack_data(data, argc - 1) < 0)
    {
        print_debug_message("Error al inicializar las pilas.");
        free(data);
        return (1);
    }
    print_debug_message("Pilas y datos inicializados.");

    // Procesar los argumentos
    if (process_arguments(data, argc, argv) < 0)
    {
        print_debug_message("Error al procesar los argumentos.");
        free(data);
        return (1);
    }
    print_debug_message("Argumentos procesados.");

    // Mostrar el estado de las pilas antes de ordenar
    print_debug_message("Estado inicial de las pilas:");
    print_stacks(data);

    // Manejar el ordenamiento
    if (handle_sorting(data) < 0)
    {
        print_debug_message("Error al ordenar las pilas.");
        free(data);
        return (1);
    }
    print_debug_message("Pilas ordenadas.");

    // Mostrar el estado final de las pilas
    print_debug_message("Estado final de las pilas:");
    print_stacks(data);

    // Liberar la memoria
    free(data);
    return (0);
}
