/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:25:19 by jrinna            #+#    #+#             */
/*   Updated: 2021/11/23 18:48:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long	ft_strchr(char *str, char c)
{
	long	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	long	i;
	long	j;

	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		new_string[j++] = s2[i++];
		s2[i - 1] = '\0';
	}
	s2 [i] = '\0';
	new_string[j] = 0;
	if (s1)
		free(s1);
	return (new_string);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	char	*new_string;
	long	i;
	long	j;

	new_string = malloc(ft_strlen(s1) + ft_strchr(s2, '\n') + 2);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			new_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\n')
	{
		new_string[j++] = s2[i++];
		s2[i - 1] = '\0';
	}
	s2[i] = '\0';
	new_string[j++] = '\n';
	new_string[j] = 0;
	if (s1)
		free(s1);
	return (new_string);
}
