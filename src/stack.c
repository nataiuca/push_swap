/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:50:42 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 14:23:16 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int init_stack_data(t_list *data, int arg_count)
{
    data->argc = arg_count;
    data->sa = malloc(sizeof(int) * arg_count);
    data->sb = malloc(sizeof(int) * arg_count);
    data->sp = malloc(sizeof(int) * arg_count);
    if (!data->sa || !data->sb || !data->sp)
    {
        free(data->sa);
        free(data->sb);
        free(data->sp);
        return (-1);
    }
    data->sia = arg_count;
    data->sib = 0;
    data->sip = arg_count;
    data->error = 0;
    return (0);
}

int process_arguments(t_list *data, int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        if (check_num(argv[i + 1]) < 0)
            return (-1);
        data->sa[i] = ft_atoi(argv[i + 1], data);
        data->sp[i] = data->sa[i];
        if (data->atoierror)
            return (-1);
        i++;
    }
    if (check_same_nums(data) < 0)
        return (-1);
    return (0);
}
