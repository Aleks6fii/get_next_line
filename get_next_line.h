#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif


char	*get_next_line(int fd);
char	*read_str(int fd, char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);


#endif
