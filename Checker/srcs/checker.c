/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:58:35 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:59:00 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init(t_all *t, t_v *v)
{
	t->stack_a = (int *)malloc(sizeof(int) * t->a);
	if (!t->stack_a)
		exit(ft_fail("couldn't allocate that much space", 0, t, v));
	t->stack_b = (int *)malloc(sizeof(int) * t->a);
	if (!t->stack_b)
		exit(ft_fail("couldn't allocate that much space", 1, t, v));
}

int	ft_success(char *s, t_all *t)
{
	free(t->stack_a);
	free(t->stack_b);
	ft_printf_fd(1, "%s\n", s);
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

int	main(int argc, char **argv)
{
	int		mark;
	t_all	t;
	t_v		*v;

	if (argc < 2)
		return (1);
	ft_count_arguments(argv, &t);
	t.b = 0;
	v = ft_lstnew(NULL);
	ft_init(&t, v);
	ft_default_stack(argv, &t, v);
	if (ft_check_duplicates(&t) == 1)
		return (ft_fail("Error", 2, &t, v));
	mark = 0;
	ft_instructions(v, &t);
	ft_print_v(v, &t);
	mark = ft_check_stacks(&t);
	ft_lstclear(&v, ft_memdel);
	if (mark == 1)
		return (ft_fail("KO", 2, &t, v));
	return (ft_success("OK", &t));
}
