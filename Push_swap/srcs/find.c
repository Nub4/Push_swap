/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:21:33 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:22:02 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_small_index_a(t_all *t, int smallest)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (++i < t->a)
		if (t->stack_a[i] == smallest)
			return (i);
	return (index);
}

int	ft_find_small_nbr_a(t_all *t)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = t->stack_a[i];
	while (++i < t->a)
		if (t->stack_a[i] < smallest)
			smallest = t->stack_a[i];
	return (smallest);
}

int	ft_find_sec_small_nbr_a(t_all *t)
{
	int	i;
	int	smallest;
	int	sec_small;

	i = 0;
	smallest = t->stack_a[i];
	sec_small = smallest;
	while (++i < t->a)
	{
		if (t->stack_a[i] < smallest)
		{
			sec_small = smallest;
			smallest = t->stack_a[i];
		}
		else if (t->stack_a[i] < sec_small && t->stack_a[i] != smallest)
			sec_small = t->stack_a[i];
	}
	return (sec_small);
}

int	ft_find_max_index_b(t_all *t, int largest)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (++i < t->b)
		if (t->stack_b[i] == largest)
			return (i);
	return (index);
}

int	ft_find_max_nbr_b(t_all *t)
{
	int	i;
	int	largest;

	i = 0;
	largest = t->stack_b[i];
	while (++i < t->b)
		if (t->stack_b[i] > largest)
			largest = t->stack_b[i];
	return (largest);
}
