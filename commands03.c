/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:43:15 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:22:48 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	write(1, "rra\n", 4);
	if (cnt_num(my_s->a, argc) > 1)
	{
		i = cnt_num(my_s->a, argc) - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
}

void	rrb(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	write(1, "rrb\n", 4);
	if (cnt_num(my_s->b, argc) > 1)
	{
		i = cnt_num(my_s->b, argc) - 1;
		tmp = my_s->b[i];
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
}

void	rrr(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	write(1, "rrr\n", 4);
	if (cnt_num(my_s->a, argc) > 1)
	{
		i = cnt_num(my_s->a, argc) - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
	if (cnt_num(my_s->b, argc) > 1)
	{
		i = cnt_num(my_s->b, argc) - 1;
		tmp = my_s->b[i++];
		while (--i > 0)
			my_s->b[i] = my_s->b[i - 1];
		my_s->b[0] = tmp;
	}
}
