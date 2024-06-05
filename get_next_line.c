#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"
#include <unistd.h>

char *read_str(int fd, char *s);

char *get_next_line(int fd)
{
    static char *string;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    string = read_str(fd, string);
    if (!string)
    {   // nothing was read
        return (NULL);
    }
    line = get_ln(string); // parse a line (ending with \n)
    char *new_string = new_str(string); // function to parse the rest of a string (after \n)
    if (!new_string) {
        string = NULL; // Prevents dangling pointer
    }
    string = new_string;
    return (line);
}

// old version 
/*
char *get_next_line(int fd)
{
	static char *string;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	string = read_str(fd, string);
	if (!string)
	{   // nothing was read
		free(string); // ??
		return (NULL);
	}
	line = get_ln(string); // parse a line (endinf with \n)
	// function to parse the rest of a string (after \n)
	string = new_str(string);
	return (line);
}
*/

char *read_str(int fd, char *s)
{
    char *buff;     // buffer to read from file
    char *temp;     // temporary pointer to hold the joined string
    int bytes;      // count read bytes

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
        temp = ft_strjoin(s, buff); // join existing string + what was read to buffer
        free(s); // free old string
        s = temp; // update s to new joined string
        if (!s) { // check for allocation failure in ft_strjoin
            free(buff);
            return (NULL);
        }
    }
    free(buff);  // free allocated memory
    return (s);  // return string 
}


// old read_str ///////////////////////////////////////////
/*
// reads a string of BUFFER_SIZE from file
// saves to cumulative variable
// char	*ft_read_to_left_str(int fd, char *left_str)
char *read_str(int fd, char *s)
{
	char *buff;     // buffer to read from file
	int bytes;      // count read bytes

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
*/


// ./a.out "text.txt"
// int main(int ac, char **av)
// int main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;

// 	fd1 = open("test.txt", O_RDONLY);

// 	i = 1;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd1);
// 		// printf("line [%02d]: %s", i, line);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);

// 	return (0);
// }
