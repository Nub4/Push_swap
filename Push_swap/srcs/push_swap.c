/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:24:57 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:25:10 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	t;
	int		i;

	if (argc < 2)
		return (0);
	ft_count_arguments(argv, &t);
	t.b = 0;
	ft_init(&t);
	ft_default_stack(argv, &t);
	i = ft_check_duplicates(&t);
	if (i == 1)
		return (ft_fail("Error", 2, &t));
	i = ft_check_stacks_ok(&t);
	if (i == 1)
	{
		if (t.a < 6)
			ft_solve_small(&t);
		else
			ft_solve(&t);
	}
	return (ft_success(&t));
}
