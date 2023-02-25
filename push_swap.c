/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:33:41 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:25:42 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		h;
	t_hell	my_s;

	for_malloc(&my_s, argc);
	for_bzero1(&my_s, argc);
	i = -1;
	while (++i < argc - 1)
		my_s.incoming[i] = ft_atoi(argv[i + 1], &my_s);
	sorting_incoming(&my_s, argc);
	fill_cont_a(&my_s, argc);
	pushing_to_b(&my_s, argc);
	while (my_s.b[0])
	{
		for_bzero2(&my_s, argc);
		h = cnt_num(my_s.b, argc);
		i = -1;
		while (++i < h)
			algorithm2(i, argc, &my_s);
		looking_min(&my_s, argc);
	}
	final_sort(&my_s, argc);
	for_free(&my_s, -1);
}

int	for_min_index(t_hell *my_s, int argc)
{
	int	min_index;
	int	min;
	int	i;

	min_index = 0;
	min = my_s->min_dist[0];
	i = -1;
	while (++i < cnt_num(my_s->min_dist, argc))
	{
		if (min > my_s->min_dist[i])
		{
			min = my_s->min_dist[i];
			min_index = i;
		}
	}
	return (min_index);
}

void	looking_min(t_hell *my_s, int argc)
{
	int	min_index;

	min_index = for_min_index(my_s, argc);
	if (my_s->pos_in_a[min_index] != 0 || min_index != 0)
	{
		if (my_s->steps[min_index] == 0)
			if_zero(my_s, min_index, argc);
		else if (my_s->steps[min_index] == 1)
			if_one(my_s, min_index, argc);
		else if (my_s->steps[min_index] == 2)
			if_two(my_s, min_index, argc);
		else if (my_s->steps[min_index] == 3)
			if_three(my_s, min_index, argc);
	}
	pa(my_s, argc);
}

void	final_sort(t_hell *my_s, int argc)
{
	int	i;

	if (my_s->a[argc - 2] != argc - 1
		&& my_s->a[argc - 2] > argc - 1 - my_s->a[argc - 2])
	{
		i = argc - 1 - my_s->a[argc - 2];
		while (i--)
			ra(my_s, argc);
	}
	else if (my_s->a[argc - 2] != argc - 1
		&& my_s->a[argc - 2] <= argc - 1 - my_s->a[argc - 2])
	{
		i = my_s->a[argc - 2];
		while (i--)
			rra(my_s, argc);
	}
}
