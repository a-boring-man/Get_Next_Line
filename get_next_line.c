/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:24:18 by jrinna            #+#    #+#             */
/*   Updated: 2021/11/30 10:27:18 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_buff(char *buff, int size)
{
	long	i;

	i = 0;
	while (!buff[i] && i < size)
		i++;
	if (i != size && ft_strchr(buff + i, '\n') == -1)
		return (ft_strjoin(NULL, buff + i));
	else if (i != size)
		return (ft_strjoin_n(NULL, buff + i));
	else
		return (NULL);
}

char	*ft_get_next_line(int fd, char *buff)
{
	char		*line;
	long		read_return_value;

	line = ft_check_buff(buff, BUFFER_SIZE);
	if (line && ft_strchr(line, '\n') != -1)
		return (line);
	read_return_value = read(fd, buff, BUFFER_SIZE);
	buff[read_return_value] = '\0';
	while (read_return_value > 0)
	{
		if (ft_strchr(buff, '\n') == -1)
			line = ft_strjoin(line, buff);
		else
			return (ft_strjoin_n(line, buff));
		read_return_value = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	return (ft_get_next_line(fd, buff));
}
