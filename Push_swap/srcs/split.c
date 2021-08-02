/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:28:46 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:28:48 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		count++;
	}
	if (s[i - 1] == c)
		return (count - 1);
	else
		return (count);
}

static int	ft_size(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static char	**ft_while_2(char **words, int count, char *str, char c)
{
	char	*word;
	int		nb;
	int		i;

	nb = -1;
	while (++nb < count)
	{
		i = 0;
		while (*str && *str == c)
			str++;
		word = (char *)malloc(sizeof(char) * (ft_size(str, c) + 1));
		if (!word)
			return (NULL);
		while (str[i] && str[i] != c)
		{
			word[i] = str[i];
			i++;
		}
		while (*str && *str != c)
			str++;
		word[i] = '\0';
		words[nb] = word;
	}
	words[nb] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	count = ft_word_count(str, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (ft_while_2(words, count, str, c));
}
