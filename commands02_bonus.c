/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands02_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:06:26 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:12:10 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a < 2)
		return ;
	i = -1;
	tmp = my_s->a[0];
	while (++i + 1 < my_s->len_a)
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i] = tmp;
}

void	rb(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_b < 2)
		return ;
	i = -1;
	tmp = my_s->b[0];
	while (++i + 1 < my_s->len_b)
		my_s->b[i] = my_s->b[i + 1];
	my_s->b[i] = tmp;
}

void	rr(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a > 1)
	{
	i = -1;
		tmp = my_s->a[0];
		while (++i + 1 < my_s->len_a)
			my_s->a[i] = my_s->a[i + 1];
		my_s->a[i] = tmp;
	}
	if (my_s->len_b > 1)
	{	
		i = -1;
		tmp = my_s->b[0];
		while (++i + 1 < my_s->len_b)
			my_s->b[i] = my_s->b[i + 1];
		my_s->b[i] = tmp;
	}
}
