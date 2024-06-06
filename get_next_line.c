#include "get_next_line.h"

char *read_str(int fd, char *s);

char *get_next_line(int fd)
{
    static char *string;
    char *line;
	char *new_string;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    string = read_str(fd, string);
    if (!string)
    {   // nothing was read
		free(string);
        return (NULL);
    }
    line = get_ln(string); // parse a line (ending with \n)
    new_string = new_str(string); // function to parse the rest of a string (after \n)
    if (!new_string) {
        string = NULL; // Prevents dangling pointer
    }
    string = new_string;
	// free(string);  // need or not?
    return (line);
}


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


// ./a.out "text.txt"
// int main(int ac, char **av)

// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	fd1 = open("read_error.txt", O_RDONLY);
// 	// fd1 = 0;
//     // while ((line = get_next_line(0)) != NULL) {
//     //     printf("%s\n", line);
//     //     free(line);
//     // }
//     // return 0;
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
