/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:38:09 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:39:01 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_words(char **words)
{
	int	k;

	k = -1;
	if (!words)
		return ;
	while (words[++k])
		free(words[k]);
	free(words);
}

void	ft_count_arguments2(char **argv, t_all *t, char **words, int i)
{
	int		k;
	int		mark;
	char	*word;

	while (argv[++i])
	{
		mark = 0;
		k = -1;
		while (argv[i][++k] && mark == 0)
		{
			if (argv[i][k] == ' ')
			{
				mark = 1;
				word = ft_strdup(argv[i]);
				words = ft_split(word, ' ');
				k = -1;
				while (words[++k])
					t->a++;
				free(word);
			}
		}
		if (mark == 0)
			t->a++;
	}
	ft_free_words(words);
}

void	ft_count_arguments(char **argv, t_all *t)
{
	int		i;
	char	**words;

	t->a = 0;
	i = 0;
	words = NULL;
	ft_count_arguments2(argv, t, words, i);
}

void	ft_default_stack2(char **argv, t_all *t, t_init *i)
{
	while (argv[i->i][++i->k] && i->mark == 0)
	{
		if (argv[i->i][i->k] == ' ')
		{
			i->mark = 1;
			i->word = ft_strdup(argv[i->i]);
			i->words = ft_split(i->word, ' ');
			i->k = -1;
			while (i->words[++i->k])
			{
				if (!ft_isnumber(i->words[i->k], t))
					exit(ft_fail("Error", 2, t));
				t->stack_a[++i->j] = ft_atoi(i->words[i->k]);
			}
			free(i->word);
		}
	}
}

void	ft_default_stack(char **argv, t_all *t)
{
	t_init	i;

	i.i = 0;
	i.j = -1;
	i.words = NULL;
	while (argv[++i.i])
	{
		i.mark = 0;
		i.k = -1;
		ft_default_stack2(argv, t, &i);
		if (i.mark == 0)
		{
			if (!ft_isnumber(argv[i.i], t))
				exit(ft_fail("Error", 2, t));
			t->stack_a[++i.j] = ft_atoi(argv[i.i]);
		}
	}
	ft_free_words(i.words);
}
