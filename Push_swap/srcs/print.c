/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:39:30 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:39:32 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_intructions(int j)
{
	if (j == 1)
		ft_printf_fd(1, "sa\n");
	else if (j == 2)
		ft_printf_fd(1, "sb\n");
	else if (j == 3)
		ft_printf_fd(1, "ss\n");
	else if (j == 4)
		ft_printf_fd(1, "ra\n");
	else if (j == 5)
		ft_printf_fd(1, "rb\n");
	else if (j == 6)
		ft_printf_fd(1, "rr\n");
	else if (j == 7)
		ft_printf_fd(1, "rra\n");
	else if (j == 8)
		ft_printf_fd(1, "rrb\n");
	else if (j == 9)
		ft_printf_fd(1, "rrr\n");
	else if (j == 10)
		ft_printf_fd(1, "pb\n");
	else if (j == 11)
		ft_printf_fd(1, "pa\n");
}
