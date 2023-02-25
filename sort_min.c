/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:11:34 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:40 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorting stack with minimum numbers

void	sorting_min(t_hell *my_s, int argc)
{
	if (argc == 3)
		sa(my_s, argc);
	else if (argc == 4)
		sort_3(my_s, argc);
	else if (argc == 5)
		sort_4(my_s, argc);
	else if (argc == 6)
		sort_5(my_s, argc);
	for_free(my_s, -1);
}

//if in stack only 3 number

void	sort_3(t_hell *my_s, int argc)
{
	if (my_s->a[0] < my_s->a[1] && my_s->a[1] > my_s->a[2]
		&& my_s->a[0] > my_s->a[2])
		rra(my_s, argc);
	else if (my_s->a[0] < my_s->a[1]
		&& my_s->a[1] > my_s->a[2]
		&& my_s->a[0] < my_s->a[2])
	{
		sa(my_s, argc);
		ra(my_s, argc);
	}
	else if (my_s->a[0] > my_s->a[1] && my_s->a[1] > my_s->a[2])
	{
		sa(my_s, argc);
		rra(my_s, argc);
	}
	else if (my_s->a[0] > my_s->a[1]
		&& my_s->a[1] < my_s->a[2]
		&& my_s->a[0] < my_s->a[2])
		sa(my_s, argc);
	else if (my_s->a[0] > my_s->a[1]
		&& my_s->a[1] < my_s->a[2]
		&& my_s->a[0] > my_s->a[2])
		ra(my_s, argc);
}

//if in stack only 4 number

void	sort_4(t_hell *my_s, int argc)
{
	int	i;

	i = 0;
	while (my_s->a)
	{
		if (my_s->a[i] == 1)
			break ;
		i++;
	}
	if (i <= 2)
		while (i-- != 0)
			ra(my_s, argc);
	else
		rra(my_s, argc);
	pb(my_s, argc);
	sort_3(my_s, argc);
	pa(my_s, argc);
}

//if in stack only 5 number

void	sort_5(t_hell *my_s, int argc)
{
	int	i;
	int	k;

	i = -1;
	k = cnt_num(my_s->a, argc);
	while (++i < k)
	{
		if (my_s->a[0] == 1 || my_s->a[0] == 2)
			pb(my_s, argc);
		else
			ra(my_s, argc);
	}
	sort_3(my_s, 4);
	if (my_s->b[0] == 1)
		sb(my_s, argc);
	pa(my_s, argc);
	pa(my_s, argc);
}
