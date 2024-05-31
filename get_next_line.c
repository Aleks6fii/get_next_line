#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// delete this later 
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
# endif
//


char *read_str(int fd, char *s);

char *get_next_line(int fd)
{
	static char *string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	string = read_str(fd, string);
	if (!string) {
		printf("nothing was read \n");
		return (NULL);
	}
	return (string);
}

// delete this functions later /////////////////////////////////////////////

int ft_strcmp(char *s1, char *s2) {
    // Compare characters until reaching the end of either string
    while (*s1 != '\0' || *s2 != '\0') {
        // If the characters are not equal, return the difference
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        // Move to the next character in each string
        s1++;
        s2++;
    }
    // If both strings are equal, return 0
    return 0;
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*pt;

	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	pt = malloc(len_s1 + len_s2 + 1);
	if (!pt)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		pt[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		pt[i + len_s1] = s2[i];
	pt[len_s1 + len_s2] = '\0';
	return (pt);
}

///////////////////////////////////////////////////////////////////////

char *read_str(int fd, char *s)
{
	char *buff;     // buffer to read from file
	int bytes;      // count read bytes
	char *endl;

	// endl = (char *)'\n';
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char)); // mem alloc buffer_size + 1
	if (!buff)                            // if allocation failed 
		return (NULL);
	bytes = 1;
	while (!ft_strchr(s, '\n') && bytes != 0) // while we did not reach end of line 
	{
		bytes = read(fd, buff, BUFFER_SIZE);  // read from file 
		if (bytes == -1)                      // if failed ???
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';      // null-terminate
		s = ft_strjoin(s, buff); // join existing string + wht was read to buffer
	}
	free(buff);  // free allocated memory
	return (s);  // return string 
}

// ./a.out "text.txt"
// int main(int ac, char **av)
int main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);

	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd1);
		// printf("line [%02d]: %s", i, line);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd1);

	return (0);
}
