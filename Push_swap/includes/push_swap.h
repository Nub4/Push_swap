/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin </var/mail/minummin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:50:34 by minummin          #+#    #+#             */
/*   Updated: 2021/05/27 13:53:12 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../ft_printf_fd/printf.h"
# include "../../get_next_line/get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_solve5
{
	int		smallest;
	int		sec_small;
	int		max;
	int		max2;
}			t_solve5;

typedef struct s_solve
{
	int		first;
	int		i;
	int		j;
	int		mark;
	int		*sorted;
	int		count;
	int		k;
	int		max;
	int		*low;
	int		*high;
	int		a;
}			t_solve;

typedef struct s_sort
{
	int		pivot;
	int		i;
	int		j;
	int		temp;
}			t_sort;

typedef struct s_init
{
	int			i;
	int			j;
	int			k;
	int			mark;
	char		*word;
	char		**words;
}				t_init;

typedef struct s_all
{
	int		*stack_a;
	int		*stack_b;
	int		a;
	int		b;
	int		chunk_low;
	int		chunk_high;
	int		chunk_count;
}			t_all;

int		ft_check_a_is_order(t_all *t);
int		ft_find_sec_small_nbr_a(t_all *t);
int		ft_find_small_index_a(t_all *t, int largest);
int		ft_find_small_nbr_a(t_all *t);
int		*ft_get_sorted_array_a(t_all *t);
int		ft_hold_second(t_all *t, int *sorted, int low, int high);
int		ft_hold_first(t_all *t, int *sorted, int low, int high);
int		ft_check_a_is_empty(t_all *t);
int		ft_find_max_index_b(t_all *t, int largest);
void	ft_sort_reverse(t_all *t);
int		ft_find_max_nbr_b(t_all *t);
int		ft_rev_rotate_both(t_all *t);
int		ft_rotate_both(t_all *t);
int		ft_swap_and_print(t_all *t);
int		ft_swap_both(t_all *t);
int		ft_swap_b(t_all *t);
int		ft_push_a(t_all *t);
int		ft_swap_a(t_all *t);
int		ft_rotate_a(t_all *t);
int		ft_rotate_b(t_all *t);
int		ft_rev_rotate_b(t_all *t);
int		ft_rev_rotate_a(t_all *t);
int		ft_push_b(t_all *t);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_isnumber(char *s, t_all *t);
int		ft_fail(char *s, int k, t_all *t);
int		ft_check_stacks_ok(t_all *t);
int		ft_check_duplicates(t_all *t);
int		ft_success(t_all *t);
char	*ft_strdup(char *s1);
char	**ft_split(char const *s, char c);
void	ft_solve_small(t_all *t);
void	ft_solve(t_all *t);
void	ft_print_intructions(int j);
void	ft_init(t_all *t);
void	ft_default_stack(char **argv, t_all *t);
void	ft_count_arguments(char **argv, t_all *t);
void	ft_quicksort(t_all *t, int low, int high);
void	ft_solve_5_push_b(t_all *t, t_solve5 s);
void	ft_do_quicksort(t_all *t);
long	ft_atoi(const char *str);

#endif
