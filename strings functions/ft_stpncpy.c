/*
NAME
****
stpncpy ---> copy a fixed-size string, returning a pointer to its end

SYNOPSIS
********
#include "mylibft.h"
char	*ft_stpncpy(char *dst, const char *src, size_t n);

PARAMETERS
**********
dst ---> the pointer to the destination array
src ---> the pointer to the string to be copied
n   ---> the number of bytes to be copied

DESCRIPTION
***********
The ft_stpncpy() function copies exactly n bytes from the string pointed to by
'src' to the array pointed to by 'dst', incluiding the terminating null byte
'\0'. The destination array must be large enough to receive the content of the
string and both memory areas may not overlap.

Exactly n bytes are written at dest, so if the length of 'src' is smaller than
'n', the remaining characters in 'dst' are filled with null bytes '\0'. On the
other hand, if the length is greater than or equal to 'n', dst will not be 
null-terminated.


RETURN VALUE
************
- A pointer to the last character in dest, incluiding the terminating null byte
  if it is in the string.
*/
/******************************************************************************/

#include "../mylibft.h"

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	while (*src && n--)
		*dst++ = *src++;
	while ((int)n-- > 0)
		*dst++ = '\0';
	return (dst);
}
