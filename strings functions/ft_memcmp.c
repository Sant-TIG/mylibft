/*
NAME
****
ft_memcmp ---> compare memory areas to at most the first n bytes

SYNOPSIS
********
#include "strings.h"
ft_memcmp(const void *str1, const void *str2, size_t n);

PARAMETERS
**********
str1 ---> the pointer to the first memory space
str2 ---> the pointer to the second memory space
n    ---> the number of bytes to be compared(at most)

DESCRIPTION
***********
The ft_memcmp() function checks whether the first n bytes of two memory spaces
are equal or not. To do this, it compares each pair of bytes until it finds a
difference or until it has compared n pair of bytes. All comparisons are done
using unsigned characters.

In any of the cases, the return value will be the difference between the last
parsed pairs of bytes, so that if all pairs bytes parsed are equal the result
is zero.

RETURN VALUE
************
- If the content of memory spaces is equal, returns zero.
- If any byte of str1 is greater than its equivalent in str2, returns greater
  than zero.
- If any byte of str1 is less than its equivalent in str2, returns less than
  zero.

*/

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (0);
}
