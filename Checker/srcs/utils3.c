/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:35:17 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 15:39:17 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rev_rotate_both(t_all *t)
{
	ft_rev_rotate_a(t);
	ft_rev_rotate_b(t);
}

int	ft_fail(char *s, int k, t_all *t, t_v *v)
{
	if (k == 1)
		free(t->stack_a);
	else if (k == 3)
	{
		free(t->stack_a);
		free(t->stack_b);
	}
	else if (k == 2)
	{
		free(t->stack_a);
		free(t->stack_b);
	}
	ft_lstclear(&v, ft_memdel);
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
