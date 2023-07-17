/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:25:19 by jrinna            #+#    #+#             */
/*   Updated: 2021/11/23 17:03:52 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long	ft_strlen(const char *s, int mode)
{
	long	i;

	i = 0;
	if (!s)
		return (0);
	if (!mode)
	{
		while (s[i])
			i++;
		return (i);
	}
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2, int mode, long i)
{
	char	*new_string;
	long	j;

	new_string = malloc(ft_strlen(s1, 0) + ft_strlen(s2, mode) + 1 + mode / 10);
	if (!new_string)
		return (NULL);
	j = -1;
	if (s1)
		while (s1[++j])
			new_string[j] = s1[j];
	else
		j = 0;
	while (s2[++i] != mode)
	{
		new_string[j + i] = s2[i];
		s2[i] = '\0';
	}
	s2[i] = 0;
	new_string[j + i++] = mode;
	if (mode)
		new_string[j + i] = '\0';
	if (s1)
		free(s1);
	return (new_string);
}
