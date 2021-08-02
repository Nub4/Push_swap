/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:39:20 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:39:23 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_a_is_empty(t_all *t)
{
	if (t->a != 0)
		return (1);
	return (0);
}

int	ft_check_a_is_order(t_all *t)
{
	int	i;
	int	mark;

	i = -1;
	mark = 0;
	while (++i < t->a - 1)
		if (t->stack_a[i] >= t->stack_a[i + 1])
			mark++;
	if (mark != 0)
		return (1);
	return (0);
}

int	ft_check_stacks_ok(t_all *t)
{
	int	i;
	int	mark;

	i = -1;
	mark = 0;
	while (++i < t->a - 1)
		if (t->stack_a[i] >= t->stack_a[i + 1])
			mark++;
	if (t->b != 0 || mark != 0)
		return (1);
	return (0);
}

int	ft_check_duplicates(t_all *t)
{
	int	i;
	int	j;
	int	mark;

	i = -1;
	mark = 0;
	while (++i < t->a - 1)
	{
		j = i + 1;
		while (j < t->a)
		{
			if (t->stack_a[i] == t->stack_a[j])
				mark++;
			j++;
		}
	}
	if (t->b != 0 || mark != 0)
		return (1);
	return (0);
}
