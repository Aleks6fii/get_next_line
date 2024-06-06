#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

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

// this function is to parse line from a string of a file 
char *get_ln(char *string)
{
	int i;
	char *ln;

	i = 0;
	if (!string[i])
		return (NULL);
	// this loop is to calculate the length of the line 
	while (string[i] && string[i] != '\n')
		i++;
	// allocate memory for the line 
	ln = malloc(sizeof(char) * (i + 2));
	if (!ln)
		return (NULL);
	i = 0;
	// write line before \n
	while (string[i] && string[i] != '\n')
	{
		ln[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		ln[i] = '\n'; // end the line if have '\n'
		i++;
	}
	ln[i] = '\0';     // and null-terminate 
	return (ln);
}

char *new_str(char *string) // pointer to the cumulative static var from the previous runs of get_next_line
{
    int i;
    int j;
    char *str;

    i = 0;
    while (string[i] && string[i] != '\n') // skip already parsed part
        i++;
    if (!string[i]) // if end of the string (file?)
    {
        free(string);
        return (NULL);
    }
    str = malloc(sizeof(char) * (ft_strlen(string) - i + 1));
    if (!str) {
        free(string);
        return (NULL);
    }
    i++;
    j = 0;
    while (string[i])
        str[j++] = string[i++]; // write what was left to the str variable
    str[j] = '\0';
    free(string);
    return (str);
}

