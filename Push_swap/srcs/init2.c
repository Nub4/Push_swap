/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:28:58 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:29:00 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_all *t)
{
	t->stack_a = (int *)malloc(sizeof(int) * t->a);
	if (!t->stack_a)
		exit(ft_fail("couldn't allocate that much space", 0, t));
	t->stack_b = (int *)malloc(sizeof(int) * t->a);
	if (!t->stack_b)
		exit(ft_fail("couldn't allocate that much space", 1, t));
}
