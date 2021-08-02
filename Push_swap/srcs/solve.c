/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:23:17 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:24:47 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_everything_to_a(t_all *t, t_solve so)
{
	so.i = 1;
	while (so.i == 1)
	{
		so.max = ft_find_max_nbr_b(t);
		if (t->stack_b[0] == so.max || t->b == 1)
			ft_print_intructions(ft_push_a(t));
		else if (ft_find_max_index_b(t, so.max) > t->b / 2)
			ft_print_intructions(ft_rev_rotate_b(t));
		else
			ft_print_intructions(ft_rotate_b(t));
		so.i = ft_check_stacks_ok(t);
	}
}

void	ft_solve_init_2(t_all *t)
{
	if (t->a == 100)
	{
		t->chunk_count = 5;
		t->chunk_low = 0;
		t->chunk_high = t->a / t->chunk_count;
	}
	else if (t->a == 500)
	{
		t->chunk_count = 11;
		t->chunk_low = 0;
		t->chunk_high = t->a / t->chunk_count + 1;
	}
	else
	{
		if (t->a < 30)
			t->chunk_count = 2;
		else if (t->a >= 30 && t->a < 200)
			t->chunk_count = 5;
		else
			t->chunk_count = 10;
		t->chunk_low = 0;
		t->chunk_high = t->a / t->chunk_count + 1;
	}
}

void	ft_solve_init(t_all *t, t_solve *so)
{
	ft_solve_init_2(t);
	so->a = t->chunk_high;
	so->low = (int *)malloc(sizeof(int) * t->chunk_count);
	so->high = (int *)malloc(sizeof(int) * t->chunk_count);
	so->i = -1;
	while (++so->i < t->chunk_count)
	{
		so->low[so->i] = t->chunk_low;
		so->high[so->i] = t->chunk_high;
		t->chunk_high = t->chunk_high + so->a;
		t->chunk_low = t->chunk_low + so->a;
	}
	so->sorted = ft_get_sorted_array_a(t);
	so->count = 0;
	so->i = 1;
	so->k = 0;
}

void	ft_put_everything_to_b(t_all *t, t_solve *so)
{
	while (++so->j < so->high[so->k] && ft_check_a_is_empty(t) == 1)
	{
		if (t->stack_a[0] == so->sorted[so->j])
		{
			ft_print_intructions(ft_push_b(t));
			so->count++;
			so->mark = 1;
			break ;
		}
	}
	if (so->mark == 0)
	{
		so->first = ft_hold_first(t, so->sorted,
				so->low[so->k], so->high[so->k]);
		if (so->first <= ft_hold_second(t, so->sorted,
				so->low[so->k], so->high[so->k]) && so->first != 0)
			ft_print_intructions(ft_rotate_a(t));
		else
			ft_print_intructions(ft_rev_rotate_a(t));
	}
	if (so->count == so->a)
	{
		so->count = 0;
		so->k++;
	}
}

void	ft_solve(t_all *t)
{
	t_solve	so;

	ft_solve_init(t, &so);
	while (so.i == 1)
	{
		so.mark = 0;
		so.j = so.low[so.k] - 1;
		ft_put_everything_to_b(t, &so);
		so.i = ft_check_a_is_empty(t);
	}
	ft_put_everything_to_a(t, so);
	free(so.sorted);
	free(so.low);
	free(so.high);
}
