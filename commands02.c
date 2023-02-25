/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:17:14 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:19:36 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->a, argc) < 2)
		return ;
	write(1, "ra\n", 3);
	i = -1;
	tmp = my_s->a[0];
	while (++i + 1 < cnt_num(my_s->a, argc))
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i] = tmp;
}

void	rb(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->b, argc) < 2)
		return ;
	write(1, "rb\n", 3);
	i = -1;
	tmp = my_s->b[0];
	while (++i + 1 < cnt_num(my_s->b, argc))
		my_s->b[i] = my_s->b[i + 1];
	my_s->b[i] = tmp;
}

void	rr(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->a, argc) > 1)
	{
		i = -1;
		tmp = my_s->a[0];
		while (++i + 1 < cnt_num(my_s->a, argc))
			my_s->a[i] = my_s->a[i + 1];
		my_s->a[i] = tmp;
	}
	if (cnt_num(my_s->b, argc) > 1)
	{	
		i = -1;
		tmp = my_s->b[0];
		while (++i + 1 < cnt_num(my_s->b, argc))
			my_s->b[i] = my_s->b[i + 1];
		my_s->b[i] = tmp;
	}
	write(1, "rr\n", 3);
}
