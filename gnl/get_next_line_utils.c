/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  faglanti <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:27:39 by  faglanti         #+#    #+#             */
/*   Updated: 2021/11/29 14:27:39 by  faglanti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	if (!str)
		return (NULL);
	res = (char *)str;
	while (*res && (*res != (char)c))
		res++;
	if (*res == (char)c)
		return (res);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*ptr;
	char			*res;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = 0;
	ptr = (char *)s1;
	while (*ptr++)
		len++;
	ptr = (char *)s2;
	while (*ptr++)
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	res = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char			*tmp;
	char			*res;
	unsigned long	len;

	if (!str)
		return (NULL);
	len = 0;
	tmp = (char *)str;
	while (*tmp++)
		len++;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	res = tmp;
	while (len--)
		*tmp++ = *str++;
	*tmp = *str;
	return (res);
}
