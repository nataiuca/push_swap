/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:02:58 by natferna          #+#    #+#             */
/*   Updated: 2025/02/17 22:02:58 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**args2data(int argc, char **args)
{
    char	**data;
    void *temp;
    int i;
    if (argc <= 2)
        return NULL;
    temp = malloc(argc * sizeof(char *));
    if (!temp)
        return (ft_printf("Error al asignar memoria"),NULL);
    data = (char **)temp;
    if (!data)
        return NULL;  
    i = 0;
    while (i < argc - 1) 
    {
        if(args[i+1])
            data[i] = ft_strdup(args[i + 1]); 
        else 
        {
            clear_data(data);
            return NULL;
        }
        i++;
    }
    data[argc-1]= NULL;
    return(data);
}
void clear_data(char** data)
{
    int i;

    if (data) {
        // Iteramos sobre el array de cadenas y liberamos cada cadena
        i = 0;
        while (data[i]) {
            free(data[i]);
            i++;
        }
        // Finalmente, liberamos el array de punteros
        free(data);
    }
}
