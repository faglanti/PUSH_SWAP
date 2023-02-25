/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:15:14 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:11:45 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_errors(t_check *my_s, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc - 1)
		{
			if (my_s->a[i] == my_s->a[j])
				for_free(my_s, 1);
		}
	}
	i = -1;
	while (++i < argc - 2)
	{
		if (my_s->a[i] > my_s->a[i + 1])
			return ;
	}
	for_free(my_s, -1);
}

void	for_free(t_check *my_s, int i)
{
	if (my_s->a != NULL)
		free(my_s->a);
	if (my_s->b != NULL)
		free(my_s->b);
	if (i == 0)
		write(2, "Memory allocation error\n", 24);
	if (i > 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	check_sort_mas_a(t_check *my_s, int argc)
{
	int	i;

	i = 0;
	if (my_s->b[0])
	{
		write(1, "KO\n", 5);
		for_free(my_s, -1);
	}
	while (i < argc - 2)
	{
		if (my_s->a[i] > my_s->a[i + 1])
		{
			write(1, "KO\n", 4);
			for_free(my_s, -1);
		}
		i++;
	}
	write(1, "OK\n", 3);
	for_free(my_s, -1);
}
