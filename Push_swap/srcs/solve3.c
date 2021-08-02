/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:28:31 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:28:36 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_5_push_b(t_all *t, t_solve5 s)
{
	if (abs(s.max - t->a / 2) > abs(s.max2 - t->a / 2))
	{
		while (t->stack_a[0] != s.smallest && t->stack_a[0] != s.sec_small)
		{
			if (s.max > t->a / 2)
				ft_print_intructions(ft_rev_rotate_a(t));
			else
				ft_print_intructions(ft_rotate_a(t));
		}
	}
	else
	{
		while (t->stack_a[0] != s.sec_small && t->stack_a[0] != s.smallest)
		{
			if (s.max2 > t->a / 2)
				ft_print_intructions(ft_rev_rotate_a(t));
			else
				ft_print_intructions(ft_rotate_a(t));
		}
	}
	ft_print_intructions(ft_push_b(t));
}
