/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:05:45 by natferna          #+#    #+#             */
/*   Updated: 2025/01/20 14:24:19 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str, t_list *d)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		{
			d->atoierror = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

void	ft_free(t_list *d)
{
	if (d->sa)
		free(d->sa);
	if (d->sp)
		free(d->sp);
	if (d->sb)
		free(d->sb);
	free(d);
	exit(EXIT_FAILURE);
}

void	ft_free2(t_list *d)
{
	if (d->sa)
		free(d->sa);
	if (d->sp)
		free(d->sp);
	if (d->sb)
		free(d->sb);
	free(d);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
