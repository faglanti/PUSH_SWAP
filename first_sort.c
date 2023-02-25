/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:55:44 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:24:30 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//looking for min in incoming stack, then sorting this stack

void	sorting_incoming(t_hell *my_s, int argc)
{
	int	q;
	int	p;
	int	min;

	check_errors(my_s, argc);
	my_s->sorted[0] = -2147483648;
	q = -1;
	min = 2147483647;
	while (++q < argc - 1)
		if (my_s->incoming[q] < min)
			min = my_s->incoming[q];
	my_s->sorted[0] = min;
	p = 0;
	while (++p < argc - 1)
	{
		q = -1;
		min = 2147483647;
		while (++q < argc - 1)
			if (my_s->incoming[q] < min
				&& my_s->incoming[q] > my_s->sorted[p - 1])
				min = my_s->incoming[q];
		my_s->sorted[p] = min;
	}
}

//looking dubs and if stacj is already sorted

void	check_errors(t_hell *my_s, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc - 1)
		{
			if (my_s->incoming[i] == my_s->incoming[j])
				for_free(my_s, 1);
		}
	}
	i = -1;
	while (++i < argc - 2)
	{
		if (my_s->incoming[i] > my_s->incoming[i + 1])
			return ;
	}
	for_free(my_s, -1);
}

//after we filling contetn_a with numbers from 1 to argc-1

void	fill_cont_a(t_hell *my_s, int argc)
{
	int	p;
	int	q;

	p = 0;
	while (p < argc - 1)
	{
		q = 0;
		while (q < argc - 1)
		{
			if (my_s->sorted[p] == my_s->incoming[q])
				my_s->a[q] = p + 1;
			q++;
		}
		p++;
	}
	if (argc < 7)
		sorting_min(my_s, argc);
}

//pushing except min and max to b

void	pushing_to_b(t_hell *my_s, int argc)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = cnt_num(my_s->a, argc);
	while (++i < cnt)
	{
		if (my_s->a[0] == 1 || my_s->a[0] == argc - 1)
			ra(my_s, argc);
		else
			pb(my_s, argc);
		if (my_s->b[0] > argc / 2)
			rb(my_s, argc);
	}
}
