/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:32:13 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:37:35 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_sorted_array_a(t_all *t)
{
	int	*sorted;
	int	*temp;
	int	i;

	temp = (int *)malloc(sizeof(int) * t->a);
	if (!temp)
		exit(ft_fail("Error", 2, t));
	sorted = (int *)malloc(sizeof(int) * t->a);
	if (!sorted)
	{
		free(temp);
		exit(ft_fail("Error", 2, t));
	}
	i = -1;
	while (++i < t->a)
		temp[i] = t->stack_a[i];
	ft_do_quicksort(t);
	i = -1;
	while (++i < t->a)
		sorted[i] = t->stack_a[i];
	i = -1;
	while (++i < t->a)
		t->stack_a[i] = temp[i];
	free(temp);
	return (sorted);
}

void	ft_quicksort_add(t_all *t, t_sort s)
{
	s.temp = t->stack_a[s.j];
	t->stack_a[s.j] = t->stack_a[s.pivot];
	t->stack_a[s.pivot] = s.temp;
}

void	ft_quicksort(t_all *t, int low, int high)
{
	t_sort	s;

	if (low < high)
	{
		s.pivot = low;
		s.i = low;
		s.j = high;
		while (s.i < s.j)
		{
			while (t->stack_a[s.i] <= t->stack_a[s.pivot] && s.i <= high)
				s.i++;
			while (t->stack_a[s.j] > t->stack_a[s.pivot] && s.j >= low)
				s.j--;
			if (s.i < s.j)
			{
				s.temp = t->stack_a[s.i];
				t->stack_a[s.i] = t->stack_a[s.j];
				t->stack_a[s.j] = s.temp;
			}
		}
		ft_quicksort_add(t, s);
		ft_quicksort(t, low, s.j - 1);
		ft_quicksort(t, s.j + 1, high);
	}
}

int	ft_hold_second(t_all *t, int *sorted, int low, int high)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = t->a;
	while (i-- > 0)
	{
		j = low - 1;
		while (++j < high)
			if (t->stack_a[i] == sorted[j])
				return (count);
		count++;
	}
	return (count);
}

int	ft_hold_first(t_all *t, int *sorted, int low, int high)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->a)
	{
		j = low - 1;
		while (++j < high)
			if (t->stack_a[i] == sorted[j])
				return (i);
	}
	return (i);
}
