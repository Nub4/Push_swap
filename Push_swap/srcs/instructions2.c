/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:22:19 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:22:44 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_a(t_all *t)
{
	int	count;
	int	tmp;
	int	i;

	i = 0;
	count = t->a - 1;
	tmp = t->stack_a[0];
	i = -1;
	while (++i < count)
		t->stack_a[i] = t->stack_a[i + 1];
	t->stack_a[i] = tmp;
	return (4);
}

int	ft_swap_b(t_all *t)
{
	int	tmp;

	tmp = t->stack_b[0];
	t->stack_b[0] = t->stack_b[1];
	t->stack_b[1] = tmp;
	return (2);
}

int	ft_swap_a(t_all *t)
{
	int	tmp;

	tmp = t->stack_a[0];
	t->stack_a[0] = t->stack_a[1];
	t->stack_a[1] = tmp;
	return (1);
}

int	ft_swap_both(t_all *t)
{
	ft_swap_a(t);
	ft_swap_b(t);
	return (3);
}

int	ft_rotate_both(t_all *t)
{
	ft_rotate_a(t);
	ft_rotate_b(t);
	return (6);
}
