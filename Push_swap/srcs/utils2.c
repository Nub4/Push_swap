/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:48:55 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 15:41:07 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_success(t_all *t)
{
	free(t->stack_a);
	free(t->stack_b);
	return (0);
}

void	ft_do_quicksort(t_all *t)
{
	int	i;

	i = 1;
	while (i == 1)
	{
		ft_quicksort(t, 0, t->a - 1);
		i = ft_check_stacks_ok(t);
	}
}

int	ft_fail(char *s, int k, t_all *t)
{
	if (k == 1)
		free(t->stack_a);
	else if (k == 2)
	{
		free(t->stack_a);
		free(t->stack_b);
	}
	ft_printf_fd(2, "%s\n", s);
	return (1);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
