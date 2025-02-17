/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:51:17 by natferna          #+#    #+#             */
/*   Updated: 2025/02/16 22:36:52 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = first;
	while (last->next)
		last = last->next;
	
	stack->top = first->next;  // Nuevo tope
	last->next = first;        // El último apunta al primero
	first->next = NULL;        // El antiguo tope es ahora el final
}


void	ra(t_stack *a, t_stack *b, t_log *log)
{
	rotate(a);
	if (log)
		add_step(log, "ra");
	else
	{
		ft_printf("ra:\n");
		print_stacks(a, b);
	}
}

void	rb(t_stack *a, t_stack *b, t_log *log)
{
	rotate(b);
	if (log)
		add_step(log, "rb");
	else
	{
		ft_printf("rb:\n");
		print_stacks(a, b);
	}
}

void	rr(t_stack *a, t_stack *b, t_log *log)
{
	rotate(a);
	rotate(b);
	if (log)
		add_step(log, "rr");
	else
	{
		ft_printf("rr:\n");
		print_stacks(a, b);
	}
}
