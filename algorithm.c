/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:17:56 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/30 20:07:56 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//counting how many command do we need in stack b

void	algorithm2(int j, int argc, t_hell *my_s)
{
	int	i;

	i = 0;
	while (my_s->a[i] && i < argc - 1)
	{
		if (my_s->b[j] > my_s->a[i])
		{
			while (my_s->a[i] && my_s->b[j] > my_s->a[i])
				i++;
			if (my_s->a[i] && my_s->b[j] < my_s->a[i])
			{
				algorithm2_2(my_s, i, j, argc);
				return ;
			}
			else
			{
				func(my_s, 0, j, argc);
				return ;
			}
		}
		i++;
	}
}

void	algorithm2_2(t_hell *my_s, int i, int j, int argc)
{
	if (i < cnt_num(my_s->a, argc) - i)
	{
		my_s->pos_in_a[j] = i;
		func(my_s, i, j, argc);
		return ;
	}
	else
	{
		my_s->pos_in_a[j] = i;
		func(my_s, i, j, argc);
		return ;
	}
}

//based on the positions of the numbers, we find
//the most advantageous number for the transfer

void	func(t_hell *my_s, int i, int j, int argc)
{
	int	four[4];

	if (i > j)
	{
		my_s->pos_in_a[j] = i;
		four[0] = i;
	}
	else
		four[0] = j;
	if (cnt_num(my_s->a, argc) - i > cnt_num(my_s->b, argc) - j)
		four[1] = cnt_num(my_s->a, argc) - i;
	else
		four[1] = cnt_num(my_s->b, argc) - j;
	four[2] = i + cnt_num(my_s->b, argc) - j;
	four[3] = j + cnt_num(my_s->a, argc) - i;
	sravnenie(four, j, my_s);
}
