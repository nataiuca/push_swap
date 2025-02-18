/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:48:25 by natferna          #+#    #+#             */
/*   Updated: 2025/02/18 00:09:09 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**parse_arguments(int argc, char **args)
{
	char	**data;

	if (argc == 2)
		return (ft_split(args[1], ' '));
	if (argc > 1)
	{
		data = args2data(argc, args);
		return (data);
	}
	else
		return (NULL);
}

int	validate_arguments(char **data)
{
	int		i;
	long	num;

	if (data)
	{
		i = 0;
		while (data[i])
		{
			if (!is_integer(data[i]))
				return (ft_printf("Error\n"), 0);
			i++;
		}
		num = ft_strtol(*data);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_printf("Error\n"), 0);
		return (1);
	}
	return (ft_printf("Error\n"), 0);
}

int	intake(int argc, char **args, t_stack *stack)
{
	char	**data;

	if (argc < 2)
		return (0);
	data = parse_arguments(argc, args);
	if (!data)
		return (0);
	if (!validate_arguments(data))
	{
		if (data)
		{
			clear_data(data);
		}
		return (0);
	}
	return (stack_transfer(data, stack));
}

int	stack_transfer(char **args, t_stack *stack)
{
	int	i;
	int	num;

	i = 0;
	while (args[i] != NULL)
		i++;
	while (i--)
	{
		if (!is_integer(args[i]))
			return (ft_printf("Error\n"), 0);
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
			return (ft_printf("Error\n"), 0);
		push(stack, num, 0);
	}
	clear_data(args);
	return (1);
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
