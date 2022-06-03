/*
NAME
****
ft_memmove ---> copy memory area. Allow overlap.

SYNOPSIS
********
#include "strings.h"
void	*ft_memmove(void *dst, const void *src, size_t n);

PARAMETERS
**********
dst ---> the pointer to the destination array
src ---> the pointer to the array to be copied
n   ---> the number of bytes to be copied

DESCRIPTION
***********
The ft_memmove() function copies n bytes from the src memory area to the dst memory
area. Before starting to copy, it verifies that the arrays passed as parameters
exist. If so it copies, from byte n to the start and directly from the source, the
first n bytes that follows the memory address stored in src.

By doing that, the memory areas may overlap. Another way to allow the overlap is
to create a temporary array, which will be a copy of src and will not overlap with
either src or dst, and then copy the content of it in dst.

RETURN VALUE
************
- A pointer to dst.
- If there is an error whith the arrays, NULL.

*/

#include "../mylibft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst || !src)
		return (FT_NULL);
	while (n--)
		*(char *)(dst + n) = *(char *)(src + n);
	return (dst);
}
