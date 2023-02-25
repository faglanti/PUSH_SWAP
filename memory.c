/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:53:36 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/30 20:27:29 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_malloc(t_hell *my_s, int argc)
{
	my_s->a = malloc(sizeof(int) * (argc - 1));
	if (!my_s->a)
		for_free(my_s, 0);
	my_s->b = malloc(sizeof(int) * (argc - 1));
	if (!my_s->b)
		for_free(my_s, 0);
	my_s->steps = malloc(sizeof(int) * (argc - 1));
	if (!my_s->steps)
		for_free(my_s, 0);
	my_s->pos_in_a = malloc(sizeof(int) * (argc - 1));
	if (!my_s->pos_in_a)
		for_free(my_s, 0);
	my_s->min_dist = malloc(sizeof(int) * (argc - 1));
	if (!my_s->min_dist)
		for_free(my_s, 0);
	my_s->incoming = malloc(sizeof(int) * (argc - 1));
	if (!my_s->incoming)
		for_free(my_s, 0);
	my_s->sorted = malloc(sizeof(int) * (argc - 1));
	if (!my_s->sorted)
		for_free(my_s, 0);
}

void	for_free(t_hell *my_s, int i)
{
	if (my_s->a != NULL)
		free(my_s->a);
	if (my_s->b != NULL)
		free(my_s->b);
	if (my_s->steps != NULL)
		free(my_s->steps);
	if (my_s->pos_in_a != NULL)
		free(my_s->pos_in_a);
	if (my_s->min_dist != NULL)
		free(my_s->min_dist);
	if (my_s->incoming != NULL)
		free(my_s->incoming);
	if (my_s->sorted != NULL)
		free(my_s->sorted);
	if (i == 0)
		write(2, "Memory allocation error\n", 24);
	if (i > 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	for_bzero1(t_hell *my_s, int argc)
{
	ft_bzero(my_s->b, argc);
	ft_bzero(my_s->pos_in_a, argc);
	ft_bzero(my_s->min_dist, argc);
}

void	for_bzero2(t_hell *my_s, int argc)
{
	ft_bzero(my_s->pos_in_a, argc);
	ft_bzero(my_s->min_dist, argc);
}
