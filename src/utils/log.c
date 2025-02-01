/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:29:18 by natferna          #+#    #+#             */
/*   Updated: 2025/02/01 22:28:53 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_log	*init_log(void)
{
	t_log	*log;

	log = malloc(sizeof(t_log));
	if (!log)
		return (NULL);
	log->count = 0;
	log->head = NULL;
	return (log);
}

void	clean_log(t_log *log)
{
	t_step	*current;
	t_step	*next;

	if (!log)
		return ;
	current = log->head;
	while (current)
	{
		next = current->next;
		free(current->step);
		free(current);
		current = next;
	}
	log->head = NULL;
	log->count = 0;
	free(log);
}

void	add_step(t_log *log, char *step)
{
	t_step	*new_step;
	t_step	*last;

	new_step = malloc(sizeof(t_step));
	if (!new_step)
		return ;
	new_step->step = ft_strdup(step);
	if (!new_step->step)
	{
		free(new_step);
		return ;
	}
	new_step->next = NULL;
	last = log->head;
	if (log->count > 0)
	{
		while (last->next)
			last = last->next;
		last->next = new_step;
	}
	else
		log->head = new_step;
	log->count++;
}

void	print_log(t_log *log)
{
	t_step	*current;

	if (!log || log->count == 0)
	{
		return ;
	}
	current = log->head;
	while (current)
	{	
		ft_printf("%s\n", current->step);
		current = current->next;
	}
}
