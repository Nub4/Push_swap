/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:29:10 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:29:59 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_2(t_all *t)
{
	if (t->stack_a[0] > t->stack_a[1])
		ft_print_intructions(ft_swap_a(t));
}

void	ft_solve_3(t_all *t)
{
	if (t->stack_a[0] > t->stack_a[1] && t->stack_a[0]
		< t->stack_a[2] && t->stack_a[1] < t->stack_a[2])
		ft_print_intructions(ft_swap_a(t));
	else if (t->stack_a[0] > t->stack_a[1] && t->stack_a[0]
		> t->stack_a[2] && t->stack_a[1] > t->stack_a[2])
	{
		ft_print_intructions(ft_swap_a(t));
		ft_print_intructions(ft_rev_rotate_a(t));
	}
	else if (t->stack_a[0] > t->stack_a[1] && t->stack_a[0]
		> t->stack_a[2] && t->stack_a[1] < t->stack_a[2])
		ft_print_intructions(ft_rotate_a(t));
	else if (t->stack_a[0] < t->stack_a[1] && t->stack_a[0]
		< t->stack_a[2] && t->stack_a[1] > t->stack_a[2])
	{
		ft_print_intructions(ft_swap_a(t));
		ft_print_intructions(ft_rotate_a(t));
	}
	else
		ft_print_intructions(ft_rev_rotate_a(t));
}

void	ft_solve_5(t_all *t)
{
	t_solve5	s;

	s.smallest = ft_find_small_nbr_a(t);
	s.sec_small = ft_find_sec_small_nbr_a(t);
	s.max = ft_find_small_index_a(t, s.smallest);
	s.max2 = ft_find_small_index_a(t, s.sec_small);
	ft_solve_5_push_b(t, s);
	s.smallest = ft_find_small_nbr_a(t);
	s.max = ft_find_small_index_a(t, s.smallest);
	while (t->stack_a[0] != s.smallest)
	{
		if (s.max > t->a / 2)
			ft_print_intructions(ft_rev_rotate_a(t));
		else
			ft_print_intructions(ft_rotate_a(t));
	}
	ft_print_intructions(ft_push_b(t));
	if (ft_check_a_is_order(t) == 1)
		ft_solve_3(t);
	if (t->stack_b[0] < t->stack_b[1])
		ft_print_intructions(ft_swap_b(t));
	ft_print_intructions(ft_push_a(t));
	ft_print_intructions(ft_push_a(t));
}

void	ft_solve_4(t_all *t)
{
	int	smallest;
	int	max;

	smallest = ft_find_small_nbr_a(t);
	max = ft_find_small_index_a(t, smallest);
	while (t->stack_a[0] != smallest)
	{
		if (max > t->a / 2)
			ft_print_intructions(ft_rev_rotate_a(t));
		else
			ft_print_intructions(ft_rotate_a(t));
	}
	ft_print_intructions(ft_push_b(t));
	if (ft_check_a_is_order(t) == 1)
		ft_solve_3(t);
	ft_print_intructions(ft_push_a(t));
}

void	ft_solve_small(t_all *t)
{
	if (t->a == 2)
		ft_solve_2(t);
	else if (t->a == 3)
		ft_solve_3(t);
	else if (t->a == 4)
		ft_solve_4(t);
	else
		ft_solve_5(t);
}
