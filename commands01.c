/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:08:20 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 11:31:32 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	i = 0;
	if (cnt_num(my_s->a, argc) < 2)
		return ;
	write(1, "sa\n", 3);
	tmp = my_s->a[0];
	my_s->a[0] = my_s->a[1];
	my_s->a[1] = tmp;
}

void	sb(t_hell *my_s, int argc)
{
	int	tmp;

	if (cnt_num(my_s->b, argc) < 2)
		return ;
	write(1, "sb\n", 3);
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	ss(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	i = 0;
	if (cnt_num(my_s->a, argc) < 2)
		return ;
	write(1, "ss\n", 3);
	tmp = my_s->a[0];
	my_s->a[0] = my_s->a[1];
	my_s->a[1] = tmp;
	if (cnt_num(my_s->b, argc) < 2)
		return ;
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	pa(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->b, argc) < 1)
		return ;
	write(1, "pa\n", 3);
	tmp = my_s->b[0];
	i = cnt_num(my_s->a, argc);
	while (i >= 0)
	{
		my_s->a[i + 1] = my_s->a[i];
		i--;
	}
	my_s->a[0] = tmp;
	while (++i < cnt_num(my_s->b, argc))
		my_s->b[i] = my_s->b[i + 1];
	my_s->b[i] = 0;
}

void	pb(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->a, argc) < 1)
		return ;
	write(1, "pb\n", 3);
	tmp = my_s->a[0];
	i = cnt_num(my_s->b, argc);
	if (i == 0)
		my_s->b[0] = tmp;
	else
	{
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
	i = -1;
	while (++i < cnt_num(my_s->a, argc) - 1)
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i] = 0;
}
