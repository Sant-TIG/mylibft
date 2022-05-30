/*
NAME
****
ft_memcpy ---> copy memory area

SYNOPSIS
********
#include "strings.h"
void	*ft_memcpy(void *dst, const void *src, size_t n);

PARAMETERS
**********
dst ---> the destination array
src ---> the array to be copied
n   ---> the number of bytes to be copied

DESCRIPTION
***********
The ft_memcpy() function copies n bytes from the src memory area to the dst memory
area. These memory areas must not overlap. In this case, use the ft_memmove()
function instead.

First, it verifies that the arrays passed as parameters exist. If so, it
directly copies from left to right the content of the src block to the dst
block. Is for this reason that memory spaces must not overlap.

The ft_memmove() function copies the content from right to left avoiding
overlapping between the memory spaces. Another way to allow overlapping is to copy
the bytes into a temporary array and then copy these into the destination block.

RETURN VALUE
************
- A pointer to dst.
- NULL.
*/

#include <stddef.h>
#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	ssize_t	i;

	i = -1;
	//printf("dst = %s y src = %s\n", dst, src);
	if (!dst || !src)
		return (NULL);
	while (++i < n)
		*(char *)(dst + i) = *(char *)(src+ i);
	return (dst);
}

/* ANOTHER WAY TO DO THE SAME

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	ssize_t	i;

	i = -1;
	printf("dst = %s y src = %s\n", dst, src);
	if (!dst || !src)
		return (NULL);
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}

*/
