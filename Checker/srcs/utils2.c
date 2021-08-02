/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:59:24 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 15:39:31 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_instructions(t_v *v, t_all *t)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			exit(ft_fail("Error", 2, t, v));
		v->str = ft_strdup(line);
		if (!v->str)
			exit(ft_fail("Error", 2, t, v));
		v->next = ft_lstnew(NULL);
		v = v->next;
	}
}

int	ft_check_stacks(t_all *t)
{
	int	i;
	int	mark;

	i = -1;
	mark = 0;
	while (++i < t->a - 1)
		if (t->stack_a[i] >= t->stack_a[i + 1])
			mark++;
	if (t->b != 0 || mark != 0)
		return (1);
	return (0);
}

void	ft_swapping(char *s, t_all *t)
{
	if (ft_strcmp(s, "sa") == 0)
		ft_swap_a(t);
	else if (ft_strcmp(s, "sb") == 0)
		ft_swap_b(t);
	else if (ft_strcmp(s, "ss") == 0)
		ft_swap_both(t);
	else if (ft_strcmp(s, "ra") == 0)
		ft_rotate_a(t);
	else if (ft_strcmp(s, "rb") == 0)
		ft_rotate_b(t);
	else if (ft_strcmp(s, "rr") == 0)
		ft_rotate_both(t);
	else if (ft_strcmp(s, "rra") == 0)
		ft_rev_rotate_a(t);
	else if (ft_strcmp(s, "rrb") == 0)
		ft_rev_rotate_b(t);
	else if (ft_strcmp(s, "rrb") == 0)
		ft_rev_rotate_both(t);
	else if (ft_strcmp(s, "pb") == 0)
		ft_push_b(t);
	else if (ft_strcmp(s, "pa") == 0)
		ft_push_a(t);
}

void	ft_print_v_2(t_v *v, t_all *t, char **words)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (v && v->next && v->str[0] != '\0')
	{
		count = 0;
		j = -1;
		while (words[++j])
			if (ft_strcmp(v->str, words[j]) == 0)
				count++;
		if (count == 0)
			exit(ft_fail("Error", 2, t, v));
		ft_swapping(v->str, t);
		v = v->next;
		i++;
	}
}

void	ft_print_v(t_v *v, t_all *t)
{
	char	*words[12];

	words[0] = "sa";
	words[1] = "sb";
	words[2] = "ss";
	words[3] = "pa";
	words[4] = "pb";
	words[5] = "ra";
	words[6] = "rb";
	words[7] = "rr";
	words[8] = "rra";
	words[9] = "rrb";
	words[10] = "rrr";
	words[11] = NULL;
	ft_print_v_2(v, t, words);
}
