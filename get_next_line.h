/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afilippo <afilippo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:10:54 by afilippo          #+#    #+#             */
/*   Updated: 2024/06/07 18:29:40 by afilippo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*read_str(int fd, char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *str);
char	*get_ln(char *string);
char	*new_str(char *string);
char	*allocate_and_copy(char *string, int start);

#endif
