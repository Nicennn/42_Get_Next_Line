/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:22:31 by niogden           #+#    #+#             */
/*   Updated: 2018/12/15 20:41:06 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *line, char *tmp, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	if (!(str = ft_strnew(ft_strlen(line) + n)))
		return (NULL);
	while (line[++i])
		str[i] = line[i];
	j = -1;
	while (tmp[++j] && j < n)
		str[i + j] = tmp[j];
	return (str);
}

int		get_line(char **line, char *tmp)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	temp = *line;
	*line = ft_strnjoin(*line, tmp, i);
	free(temp);
	if (tmp[i] == '\n')
		return (1);
	return (0);
}

int		clear(char **tmp)
{
	char	*temp;

	temp = *tmp;
	*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	free(temp);
	return (1);
}

int		ft_read(int fd, char **line, char **tmp)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (get_line(line, buff))
		{
			temp = *tmp;
			*tmp = ft_strjoin(*tmp, ft_strchr(buff, '\n') + 1);
			free(temp);
			return (1);
		}
	}
	return ((**line) ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmp = NULL;

	if (!line || fd < 0)
		return (-1);
	if (!tmp)
		if (!(tmp = ft_strdup("")))
			return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (*tmp)
	{
		if (get_line(line, tmp))
			return ((clear(&tmp)));
		if (!(tmp = ft_strdup("")))
			return (-1);
	}
	return (ft_read(fd, line, &tmp));
}
