/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afilippo <afilippo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:18:36 by afilippo          #+#    #+#             */
/*   Updated: 2024/06/07 18:27:06 by afilippo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocate_and_copy(char *string, int start);

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
