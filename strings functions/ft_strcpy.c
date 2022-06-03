/*
NAME
****
strcpy ---> copy a string

SYNOPSIS
********
#include "mylibft.h"
char	*ft_strcpy(char *dst, const char *src);

PARAMETERS
**********
dst ---> the pointer to the destination array
src ---> the pointer to the string to be copied

DESCRIPTION
***********
The ft_strcpy() function copies the string pointed to by 'src' to the array
pointed to by 'dst', incluiding the terminating null byte '\0'.The destination
array must be large enough to receive the content of the string and both memory
areas may not overlap.

RETURN VALUE
************
- A pointer to the destination string.

*/

#include <unistd.h>

char	*ft_strcpy(char *dst, const char *src)
{
	ssize_t	i;

	i = -1;
	while (*src)
		*(dst + ++i) = *src++;
	*(dst + ++i) = '\0';
	return (dst);
}
