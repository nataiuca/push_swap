/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:02:58 by natferna          #+#    #+#             */
/*   Updated: 2025/02/18 00:30:44 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**args2data(int argc, char **args)
{
	char	**data;
	void	*temp;
	int		i;

	if (argc <= 2)
		return (NULL);
	temp = malloc(argc * sizeof(char *));
	if (!temp)
		return (ft_printf("Error al asignar memoria"), NULL);
	data = (char **)temp;
	if (!data)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (args[i + 1])
			data[i] = ft_strdup(args[i + 1]);
		else
		{
			return (clear_data(data), NULL);
		}
		i++;
	}
	data[argc - 1] = NULL;
	return (data);
}

void	clear_data(char **data)
{
	int	i;

	if (data)
	{
		i = 0;
		while (data[i])
		{
			free(data[i]);
			i++;
		}
		free(data);
	}
}
