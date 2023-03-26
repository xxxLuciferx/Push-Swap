/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:32:23 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/23 17:50:21 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	*get_first(char *static_string)
{
	char	*line;
	int		i;

	i = 0;
	while (static_string && static_string[i] && static_string[i] != '\n')
		i++;
	line = malloc(i + 2);
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = static_string[i];
		i--;
	}
	if (my_strlen(line) == 0)
	{
		free (line);
		line = NULL;
	}
	return (line);
}

char	*get_last(char *static_string)
{
	char	*line;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	while (static_string && static_string[i] != '\n' && static_string[i])
		i++;
	if (my_strlen(static_string) == i)
		return (NULL);
	size = my_strlen(static_string) - i;
	line = malloc(size + 1);
	while (size)
	{
		line[j] = static_string[i + 1];
		i++;
		j++;
		size--;
	}
	line[j] = '\0';
	return (line);
}

int	ft_strchr(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] && string)
	{
		if (string[i] == c)
			return (1);
		i++;
	}	
	return (0);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	string = malloc(my_strlen(s1) + my_strlen(s2) + 1);
	while (s1 && s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		string[j + i] = s2[j];
		j++;
	}
	string[j + i] = '\0';
	free(s1);
	return (string);
}