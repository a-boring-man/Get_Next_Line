/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:24:18 by jrinna            #+#    #+#             */
/*   Updated: 2021/11/23 17:44:55 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	char		*line;
	long		read_return_value;
	long		i;

	i = 0;
	line = NULL;
	while (fd >= 0 && fd < OPEN_MAX && !buff[fd][i] && i < BUFFER_SIZE)
		i++;
	if (fd >= 0 && i != BUFFER_SIZE && ft_strlen(buff[fd] + i, 1) == -1)
		line = ft_strjoin(line, buff[fd] + i, 0, -1);
	else if (fd >= 0 && fd < OPEN_MAX && i != BUFFER_SIZE)
		return (ft_strjoin(line, buff[fd] + i, 10, -1));
	read_return_value = read(fd, buff[fd], BUFFER_SIZE);
	if (fd >= 0 && fd < OPEN_MAX)
		buff[fd][read_return_value] = '\0';
	while (fd >= 0 && fd < OPEN_MAX && read_return_value > 0)
	{
		if (ft_strlen(buff[fd], 1) == -1)
			line = ft_strjoin(line, buff[fd], 0, -1);
		else
			return (ft_strjoin(line, buff[fd], 10, -1));
		read_return_value = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (line);
}
