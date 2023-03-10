/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:17:34 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/31 13:19:05 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		i;
	t_check	my_s;

	for_malloc(&my_s, argc);
	ft_bzero(my_s.b, argc);
	i = -1;
	while (++i < argc - 1)
		my_s.a[i] = ft_atoi(argv[i + 1], &my_s);
	check_errors(&my_s, argc);
	my_s.len_a = argc - 1;
	my_s.len_b = 0;
	check_command_text(&my_s, argc);
}

void	for_malloc(t_check *my_s, int argc)
{
	my_s->a = malloc(sizeof(int) * (argc - 1));
	if (!my_s->a)
		for_free(my_s, 0);
	my_s->b = malloc(sizeof(int) * (argc - 1));
	if (!my_s->b)
		for_free(my_s, 0);
}

void	check_command_text(t_check *my_s, int argc)
{
	char	*str;

	str = NULL;
	str = get_next_line(0);
	while (str)
	{
		if (!ft_strncmp(str, "ra\n", 4))
			ra(my_s);
		else if (!ft_strncmp(str, "rb\n", 4))
			rb(my_s);
		else
			actions_in_stack(my_s, str);
		free(str);
		str = get_next_line(0);
	}
	check_sort_mas_a(my_s, argc);
}

void	actions_in_stack(t_check *my_s, char *str)
{
	if (!ft_strncmp(str, "rr\n", 4))
		rr(my_s);
	else if (!ft_strncmp(str, "rra\n", 5))
		rra(my_s);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrb(my_s);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rrr(my_s);
	else if (!ft_strncmp(str, "sa\n", 4))
		sa(my_s);
	else if (!ft_strncmp(str, "sb\n", 4))
		sb(my_s);
	else if (!ft_strncmp(str, "ss\n", 4))
		ss(my_s);
	else if (!ft_strncmp(str, "pa\n", 4))
		pa(my_s);
	else if (!ft_strncmp(str, "pb\n", 4))
		pb(my_s);
	else
	{
		free(str);
		for_free(my_s, 1);
	}
}
