/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faglanti <faglanti@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:12:41 by faglanti          #+#    #+#             */
/*   Updated: 2022/01/30 18:59:12 by faglanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(char *str, t_check *my_s)
{
	int			i;
	int			s;
	long int	result;

	i = 0;
	s = 1;
	result = 0;
	if (ft_strlen(str) > 11)
		for_free(my_s, 1);
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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char)str1[i] || (unsigned char)str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
