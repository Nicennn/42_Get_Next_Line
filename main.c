/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:29:24 by niogden           #+#    #+#             */
/*   Updated: 2019/02/27 17:10:02 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char *av[])
{
	int		fd;
	char	*line;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	close(fd);
	return (0);
}
