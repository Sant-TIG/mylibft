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
dst ---> the pointer to the the destination array
src ---> the pointer to the the array to be copied
n   ---> the number of bytes to be copied

DESCRIPTION
***********
The ft_memcpy() function copies n bytes from the src memory area to the dst memory
area. Before starting to copy, it verifies that the arrays passed as parameters
exist. If so it copies, in order and directly from the source, the first n bytes
that follows the memory address stored in src.

Is for this reason that memory areas must not overlap, since the data could be
overwritten. In these cases, use the ft_memmove() function instead.

RETURN VALUE
************
- A pointer to dst.
- If there is an error whith the arrays, NULL.

*/

#include "../mylibft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (FT_NULL);
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src+ i);
		i++;
	}
	return (dst);
}