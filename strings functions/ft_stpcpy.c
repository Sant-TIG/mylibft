/*
NAME
****
stpcpy ---> copy a string returning a pointer to its end

SYNOPSIS
********
#include "mylibft.h"
char	*ft_stpcpy(char *dst, const char *src);

PARAMETERS
**********
dst ---> the pointer to the destination array
src ---> the pointer to the string to be copied

DESCRIPTION
***********
The ft_stpcpy() function copies the string pointed to by 'src' to the array
pointed to by 'dst', incluiding the terminating null byte '\0'.The destination
array must be large enough to receive the content of the string and both memory
areas may not overlap.

This function is intended to be used as a replacement to strcat() function in
situations when you need to concatenate multiple substrings into one string. By
using this function, you save yourself rescanning the destination string for its
end on every concatenation.

RETURN VALUE
************
- A pointer to the end of the destination string.
*/

char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
