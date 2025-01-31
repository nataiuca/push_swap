/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:48:25 by natferna          #+#    #+#             */
/*   Updated: 2025/01/31 23:10:29 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**parse_arguments(int argc, char **args)
{
	char	**data;
	int		i;

	if (argc == 2)
		return (ft_split(args[1], ' '));
	data = (char **)malloc((argc) * sizeof(char *));
	i = 0;
	while (i < argc - 1)
	{
		data[i] = ft_strdup(args[i + 1]);
		i++;
	}
	data[argc - 1] = NULL;
	return (data);
}

int	validate_arguments(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (!is_integer(data[i]))
			return (ft_printf("Error\n"), 0);
		i++;
	}
	return (1);
}

int	intake(int argc, char **args, t_stack *stack)
{
	char	**data;

	if (argc == 1)
		return (0);
	data = parse_arguments(argc, args);
	if (!validate_arguments(data))
		return (0);
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
			return (0);
		num = ft_atoi(args[i]);
		if (num > INT_MAX || num < INT_MIN || is_duplicate(stack, num))
			return (ft_printf("Error\n"), 0);
		push(stack, num, 0);
	}
	return (1);
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
