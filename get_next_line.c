/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afilippo <afilippo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:10:45 by afilippo          #+#    #+#             */
/*   Updated: 2024/06/07 18:27:43 by afilippo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *s);
char	*read_until_newline(int fd, char *s, char *buff);
char	*new_str(char *string);
char	*allocate_and_copy(char *string, int start);

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;
	char		*new_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_str(fd, string);
	if (!string)
	{
		free(string);
		return (NULL);
	}
	line = get_ln(string);
	new_string = new_str(string);
	if (!new_string)
		string = NULL;
	string = new_string;
	return (line);
}

char	*read_str(int fd, char *s)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	s = read_until_newline(fd, s, buff);
	free(buff);
	return (s);
}

char	*read_until_newline(int fd, char *s, char *buff)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(s, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(s);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = ft_strjoin(s, buff);
		free(s);
		s = temp;
		if (!s)
		{
			free(buff);
			return (NULL);
		}
	}
	return (s);
}

char	*new_str(char *string)
{
	int		i;
	char	*str;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	i++;
	str = allocate_and_copy(string, i);
	if (!str)
	{
		return (NULL);
	}
	if (!(*str))
	{
		free(str);
		free(string);
		return (NULL);
	}
	free(string);
	return (str);
}

char	*allocate_and_copy(char *string, int start)
{
	int		j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(string) - start + 1));
	if (!str)
	{
		free(string);
		return (NULL);
	}
	while (string[start])
		str[j++] = string[start++];
	str[j] = '\0';
	return (str);
}
