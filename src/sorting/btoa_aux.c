/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:17:21 by natferna          #+#    #+#             */
/*   Updated: 2025/02/13 22:55:26 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sync_rotate(t_stacksys *stacks, int dir)
{
	if (dir > 0)
		rr(stacks->a, stacks->b, stacks->log);
	else
		rrr(stacks->a, stacks->b, stacks->log);
}

void	btoa_step(t_stacksys *stacks, int rem_a, int rem_b)
{
	if (rem_a > 0)
		ra(stacks->a, stacks->b, stacks->log);
	else if (rem_a < 0)
		rra(stacks->a, stacks->b, stacks->log);
	if (rem_b > 0)
		rb(stacks->a, stacks->b, stacks->log);
	else if (rem_b < 0)
		rrb(stacks->a, stacks->b, stacks->log);
}

int	min_cost(int ramp_a, int ramp_b)
{
	int	cost;

	if ((ramp_a > 0 && ramp_b > 0) || (ramp_a < 0 && ramp_b < 0))
	{
		if (ft_abs(ramp_a) > ft_abs(ramp_b))
			cost = ft_abs(ramp_a);
		else
			cost = ft_abs(ramp_b);
	}
	else
		cost = ft_abs(ramp_a) + ft_abs(ramp_b);
	return (cost);
}

void	init_atob(t_stacksys *stacks)
{
	int	link;
	int	nxt;

	while (stacks->a->size > 5)
	{
		link = mean_index(stacks->a);
		nxt = stacks->a->top->index;
		if (nxt < link)
			pb(stacks->a, stacks->b, stacks->log);
		else
			ra(stacks->a, stacks->b, stacks->log);
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
