/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  faglanti <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:20:34 by  faglanti         #+#    #+#             */
/*   Updated: 2021/11/25 15:20:34 by  faglanti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_to_read(int fd, char *temp)
{
	char	*str;
	char	*buff;
	int		byte;

	byte = 1;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr(temp, '\n') && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		str[byte] = '\0';
		buff = temp;
		if (!temp)
			temp = ft_strdup(str);
		else
			temp = ft_strjoin(temp, str);
		if (buff)
			free (buff);
	}
	free (str);
	return (temp);
}

char	*ft_to_static(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strchr(str, '\n');
	if (!tmp)
		return (NULL);
	tmp++;
	str = tmp;
	i = ft_strlen(tmp);
	if (i == 0)
		return (NULL);
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_to_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*str;
	char			*line;
	static char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_to_read(fd, temp);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	temp = ft_to_static(str);
	line = ft_to_line(str);
	free(str);
	return (line);
}
