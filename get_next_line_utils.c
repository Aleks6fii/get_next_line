#include <unistd.h>

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

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char) c;
	printf("char: %c\n", ch);
	printf("int: %i\n", ch);
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (0);
}

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
