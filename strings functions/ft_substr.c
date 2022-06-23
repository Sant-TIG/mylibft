/*
NAME
****
ft_substr ---> extract a substring from a string

SYNOPSIS
********
#include "strings.h"
char	*ft_substr(const char *str, unsgined int start, size_t len);

PARAMETERS
**********
str   ---> the string where to extract the substring
start ---> the index of the string where the substring starts
len   ---> the maximum length of the substring

DESCRIPTION
***********
The ft_substr() function extracts a substring from a string. This substring
will start from the 'start' index of the string and will have a maximum length
of 'len' bytes. However, there are two things to keep in mind:

- The value of 'start' must not be greater than the length of 'str'. In that
case, it returns a string consisiting of a single null character.

- The number of bytes to be copied is always limited to a maximum equal to the
number of bytes that can be copied from the original string from the 'start'
position to the end of the string.

RETURN VALUE
************
- A pointer to the substring.
- If 'start' is greater than the length of 'str', returns a string consisting of
a single null character.
- If there is an error allocating the memory space, it returns NULL.
*/

#include "../mylibft.h"
#include <unistd.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	new_len;
	ssize_t	i;
	char	*dst;

	if (start > ft_strlen(str))
		return (ft_strdup("\0"));
	str = str + start;
	new_len = ft_strlen (str);
	if (len > new_len)
		len = new_len;
	dst = (char *)malloc(sizeof(char) * new_len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);	
}
