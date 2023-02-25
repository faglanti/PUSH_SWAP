/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:51:24 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/30 20:49:54 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_hell *my_s)
{
	int			i;
	int			s;
	long int	result;

	i = 0;
	s = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		for_free(my_s, 1);
	while (str[i] > 47 && str[i] < 58)
		result = result * 10 + (str[i++] - '0');
	result = result * s;
	if (result < -2147483648 || result > 2147483647)
		for_free(my_s, 1);
	return (result);
}

void	ft_bzero(int *content, int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		content[i] = 0;
}

int	cnt_num(int *content, int argc)
{
	int	i;

	i = 0;
	while (content[i] && i < argc - 1)
		i++;
	return (i);
}
