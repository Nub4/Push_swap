/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:49:07 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:49:51 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_a(t_all *t)
{
	int	a;
	int	b;
	int	i;

	if (t->b == 0)
		return (0);
	a = t->a;
	b = t->b;
	while (0 < a)
	{
		t->stack_a[a] = t->stack_a[a - 1];
		a--;
	}
	t->stack_a[0] = t->stack_b[0];
	i = -1;
	while (++i < b)
		t->stack_b[i] = t->stack_b[i + 1];
	(t->a)++;
	(t->b)--;
	return (11);
}

int	ft_push_b(t_all *t)
{
	int	a;
	int	b;
	int	i;

	if (t->a == 0)
		return (0);
	a = t->a;
	b = t->b;
	while (0 < b)
	{
		t->stack_b[b] = t->stack_b[b - 1];
		b--;
	}
	t->stack_b[0] = t->stack_a[0];
	i = -1;
	while (++i < a)
		t->stack_a[i] = t->stack_a[i + 1];
	(t->a)--;
	(t->b)++;
	return (10);
}

int	ft_rev_rotate_b(t_all *t)
{
	int	count;
	int	tmp;

	count = t->b - 1;
	tmp = t->stack_b[count];
	count++;
	while (0 < --count)
		t->stack_b[count] = t->stack_b[count - 1];
	t->stack_b[count] = tmp;
	return (8);
}

int	ft_rev_rotate_a(t_all *t)
{
	int	count;
	int	tmp;

	count = t->a - 1;
	tmp = t->stack_a[count];
	count++;
	while (0 < --count)
		t->stack_a[count] = t->stack_a[count - 1];
	t->stack_a[count] = tmp;
	return (7);
}

int	ft_rotate_b(t_all *t)
{
	int	count;
	int	tmp;
	int	i;

	i = 0;
	count = t->b - 1;
	tmp = t->stack_b[0];
	i = -1;
	while (++i < count)
		t->stack_b[i] = t->stack_b[i + 1];
	t->stack_b[i] = tmp;
	return (5);
}
